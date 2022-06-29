#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool sorted(int arr[], int n)
{
    if (n == 1)
        return true;
    bool restArray = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (arr[i] == key)
        return i;
    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
        return restArray;
    if (arr[i] == key)
        return i;
    return -1;
}

void reverse(string s)
{
    if (s.length() == 0)
        return;
    string ros = s.substr(1);
    reverse(ros);
    cout << s[0];
}

void replacePi(string s)
{
    if (s.length() == 0)
        return;
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n, char src, char dest, char helper)
{

    if (n == 0)
        return;

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

string removeDup(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if (ch == ans[0])
        return ans;
    return ch + ans;
}

string moveallX(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];

    string ans = moveallX(s.substr(1));
    if (ch == 'x')
        return ans + ch;
    else
        return ch + ans;
}

void subseq(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << ln;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + ch);
}

void subSeqWithASCII(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << ln;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans + ch);
    subseq(ros, ans + to_string(code));
}

string keypadArr[] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    } 

    char ch = s[0];
    string code = keypadArr[ch-'0'];
    string ros = s.substr(1);

    for(int i = 0; i < code.length(); i++){
        keypad(ros, ans + code[i]);
    }
}

void solve()
{
    // int arr[] = {1,2,3,4,5};
    // int arr[] = {1,2,3,4,8,5};
    // cout<<sorted(arr,6)<<endl;

    // int arr[] = {4,2,1,2,5,2,7};
    // cout<<firstocc(arr, 7, 0, 2)<<endl;
    // cout<<lastocc(arr, 7, 0, 2)<<endl;

    // reverse("shivang");
    // replacePi("pippppiiiipi");

    // towerOfHanoi(3, 'A', 'C', 'B');

    // cout<<removeDup("aaaaaabbbbbbbccnnnadddddddd")<<endl;
    // cout<<moveallX("axxbdxcefxhix")<<endl;
    // subseq("ABC", "");
    // subSeqWithASCII("ABC", "");
    keypad("23", "");
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
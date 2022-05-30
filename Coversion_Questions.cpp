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
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int binaryToDecimal(int n){
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int l = n%10;
        ans += x*l;
        x *= 2;
        n /= 10;
    }
    return ans;   
}

int octalToDecimal(int n){
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int l = n%10;
        ans += x*l;
        x *= 8;
        n /= 10;
    }
    return ans;
}

int hexadecimalToDecimal(string n){
    int ans = 0;
    int x = 1;
    int s = n.size();

    for (int i = s-1; i >= 0; i--)
    {
        if(n[i] >= '0' && n[i] <= '9'){
            ans += x*(n[i] - '0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F'){
            ans += x*(n[i] - 'A' + 10);
        }
        x *= 16;
    }
    return ans;
}

int decimalToBinary(int n){
    int x = 1;
    int ans = 0;
    while (x <= n)
    {
        x *= 2;
    }
    x /= 2;

    while (x > 0)
    {
        int ld = n/x;
        n -= ld*x;
        x/=2;
        ans = ans*10 + ld;
    }
    return ans;    
}

int decimalToOctal(int n){
    int x = 1;
    int ans = 0;
    while (x <= n)
    {
        x *= 8;
    }
    x /= 8;

    while (x > 0)
    {
        int ld = n/x;
        n -= ld*x;
        x/=8;
        ans = ans*10 + ld;
    }
    return ans;    
}

string decimalToHexadecimal(int n){
    int x = 1;
    string ans = "";
    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;

    while (x > 0)
    {
        char ld = (n/x >= 10)?((n/x - 10) + 'A'): (n/x) + '0';
        int old = n/x;
        n -= old*x;
        x/=16;
        cout<<ld;
    }

    return ans;
}

int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int addBinary(int a, int b){
    int ans = 0;
    int prevCarry = 0;

    while (a>0 && b>0)
    {
        if(a%2 == 0 && b%2 == 0){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        else if((a%2 == 0 && b%2 == 1) || (a%2 == 1 && b%2 == 0)){
            if (prevCarry == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1; 
            }
            else{
                ans = ans*10 +1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }

        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {
        if(prevCarry == 1){
            if (a%2 == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (a%2);
        }
        a/=10;
    }

    while (b > 0)
    {
        if(prevCarry == 1){
            if (b%2 == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (b%2);
        }
        b/=10;
    }

    if (prevCarry == 1)
    {
        ans = ans*10 + 1;
    }
    
    return reverseDigits(ans);
}

void solve(){
    cout<<binaryToDecimal(1010)<<endl;
    cout<<octalToDecimal(17)<<endl;
    cout<<hexadecimalToDecimal("1CF")<<endl;
    cout<<decimalToBinary(10)<<endl;
    cout<<decimalToOctal(15)<<endl;
    cout<<decimalToHexadecimal(154)<<endl;
    cout<<addBinary(1011,1100)<<endl;
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
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}
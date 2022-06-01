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

const int N = 1e6 + 2;
int idx[N];
bool check[N];

int minRepeatingIndex(int arr[], int size)
{
    int minidx = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (idx[arr[i]] != 0)
            minidx = min(minidx, idx[arr[i]]);
        else
            idx[arr[i]] = i;
    }

    if (minidx == INT_MAX)
        return -1;
    else
        return minidx + 1;
}

void subArrayWithGivenSum(int arr[], int size, int s)
{
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    
    while (j < size && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }

    if (sum == s)
    {
        cout << i + 1 << " " << j + 1 << endl;
        return;
    }

    while (j < size)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == s)
        {
            st = i + 1;
            en = j + 1;
            break;
        }

        j++;
    }

    cout << st << " " << en << endl;
}

int smallestPossitiveMissingNumber(int arr[], int size){
    for (int i = 0; i < size; i++)
        if(arr[i] >= 0) check[arr[i]] = 1;
    
    int ans = -1;
    for (int i = 1; i < N; i++)
        if(check[i] == false) {ans = i; break;}
    
    return ans;
}

void solve()
{
    // int arr[7] = {1,8,3,4,3,5,6};
    // cout<<minRepeatingIndex(arr,7);

    // int arr[5] = {1,2,3,7,5};
    // subArrayWithGivenSum(arr, 5, 12);

    int arr[6] = {0,-9,1,3,-4,5};
    cout<<smallestPossitiveMissingNumber(arr,6);
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
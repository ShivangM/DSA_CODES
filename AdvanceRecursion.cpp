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

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    forn(i, s.length())
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutation(ros, ans + ch);
    }
}

int countPath(int s, int e)
{
    if (s == e)
        return 1;
    if (s > e)
        return 0;
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }
    return count;
}

int countPathMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;
    return countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1);
}

int tillingWays(int n){
    if(n==0 || n==1) return n;
    return tillingWays(n-1) + tillingWays(n-2);
}

int friendsPairing(int n){
    if(n==0 || n==1 || n==2) return n;
    return friendsPairing(n-1) + friendsPairing(n-2)*(n-1);
}

int knapsack(vp32 items,int n, int W){
    if(n==0 || W==0) return 0; if(items[n-1].fi > W) return knapsack(items, n-1, W);
    return max(knapsack(items, n-1, W-items[n-1].fi) + items[n-1].se, knapsack(items, n-1, W));
}

void solve()
{
    // permutation("ABCD", "");
    // cout<<countPath(0,3)<<endl;
    // cout << countPathMaze(3, 0, 0) << endl;
    // cout<<tillingWays(4)<<ln;
    // cout<<friendsPairing(4)<<endl;
    vp32 items = {{10,100},{20,50},{30,150}};
    cout<<knapsack(items, 3, 50)<<endl;
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
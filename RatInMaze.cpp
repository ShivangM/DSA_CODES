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

bool isSafe(vv32 &maze, int x, int y, int n)
{
    if (x < n && y < n && maze[x][y] == 1)
        return true;
    return false;
}

pair<bool, vv32> ratInMaze(vv32 &maze, int x, int y, int n, vv32 &sol)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return {true, sol};
    }

    if (isSafe(maze, x, y, n))
    {
        sol[x][y] = 1;
        if (ratInMaze(maze, x + 1, y, n, sol).fi)
            return {true, sol};
        if (ratInMaze(maze, x, y + 1, n, sol).fi)
            return {true, sol};
        sol[x][y] = 0;
        return {false, sol}; // backtracking
    }
    return {false, sol};
}

void printVV32(vv32 v, int n)
{
    forn(i, n)
    {
        forn(j, n) { cout << v[i][j] << " "; }
        cout << ln;
    }
}

void solve()
{
    vv32 maze = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}};

    vv32 sol = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    pair<bool, vv32> ans = ratInMaze(maze, 0, 0, 5, sol);
    if (ans.fi)
        printVV32(ans.se, 5);
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
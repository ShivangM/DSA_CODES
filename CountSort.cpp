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

bool myCheck(p32 p1, p32 p2){
    return p1.fi < p2.fi;
}

void countSort(v32 &arr){
    int k = arr[0]; forn(i, arr.size()) k = max(k, arr[i]);
    v32 count(k+1,0); forn(i, arr.size()) count[arr[i]]++;
    for(int i = 1; i <= k+1; i++) count[i] += count[i-1];
    v32 output(arr.size(), 0); rforn(i, arr.size() - 1) output[--count[arr[i]]] = arr[i];
    forn(i, arr.size()) arr[i] = output[i];
}

void solve(){
    // vp32 arr = {{10,0},{16,1},{7,2},{14,3},{5,4},{3,5},{12,6},{9,7}};
    // sort(arr.begin(), arr.end(), myCheck);
    // forn(i, arr.size()) cout<<arr[i].se<<" ";

    v32 arr = {1,3,2,3,4,1,6,4,3};
    countSort(arr); 
    forn(i, arr.size()) cout<<arr[i]<<" ";
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
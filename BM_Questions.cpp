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
 
bool isPowerof2(int n){
    return (n && !(n & n-1));
}

void subset(int arr[], int n){
    for(int i = 0; i < (1<<n); i++){
        forn(j, n){
            // Identify wether 1 or 0
            if(i & (1<<j)){
                // If 1 then 
                cout<<arr[j]<<" ";
            }
        }
        cout<<ln;
    }
}

int numberOfOnes(int n){
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int uniqueNumber(int arr[], int n){
    int xorsum = 0;
    forn(i,n) xorsum = xorsum^arr[i];
    return xorsum;
}

int getBit(int n, int pos){
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos){
    return  (n | (1 << pos));
}

p32 doubleUnique(int arr[], int n){
    int xorsum = 0; int newxor = 0;
    int setbit = 0; int pos = 0; int tempxor = xorsum;
    forn(i,n) xorsum = xorsum^arr[i];
    while (setbit != 1) { setbit = xorsum & 1; pos++; xorsum = xorsum >> 1;}
    forn(i, n) if(getBit(arr[i], pos-1)) newxor = newxor^arr[i];
    p32 ans; ans.fi = newxor; ans.se = tempxor^newxor;
    return ans;
}

int uniqueInTriplets(int arr[], int n){
    int result = 0;
    forn(i, 64){ int sum = 0; 
        forn(j, n) if(getBit(arr[j], i)) sum++;
        if (sum % 3) result = setBit(result, i);
    }
    return result;
}

void solve(){
    int n; cin>>n;
    // cout<<isPowerof2(n)<<endl;
    // cout<<numberOfOnes(n)<<endl;

    // int arr[4] = {1,2,3,4};
    // subset(arr, 4);

    // int arr[7] = {1,2,3,4,1,2,3};
    // cout<<uniqueNumber(arr, 7);

    // int arr[] = {1,2,3,1,2,3,5,7};
    // p32 uniqueNums = doubleUnique(arr, 8);
    // cout<<uniqueNums.fi<<" "<<uniqueNums.se<<ln;

    int arr[] = {1,2,3,4,1,2,3,1,2,3};
    cout<<uniqueInTriplets(arr, 10)<<endl;
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
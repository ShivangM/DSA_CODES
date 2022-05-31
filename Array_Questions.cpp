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

void maxTillI(int arr[], int size){
    int mx = INT_MIN;

    cout<<"MAX Till I: ";
    for (int i = 0; i < size; i++)
    {
        mx = max(mx, arr[i]);
        cout<<mx<<" ";
    }
    cout<<endl;
}

/*
    Sub Array: Contiguous Part Of Array
    NO. of subarray with n elements in a array = nC2 + n = n*(n-1)/2

    A subsequence is a sequence that can be derived an array by selecting zero or 
    more elements, without changing the order of the remaining elements.

    Subsequence is not contiguous but remain in order

    NO. of subsequence of an array with n elements = 2^n

    Every subarray is a subsequence but every subsequence is not a subarray.
*/

void sumOfAllSubarrays(int arr[], int size){
    int curr = 0;

    cout<<"Sum Of all Subarrys: "<<endl;
    for (int i = 0; i < size; i++)
    {
        curr = 0;
        for (int j = i; j < size; j++)
        {
            curr += arr[j];
            cout<<curr<<" ";
        }
        cout<<endl;
    }
}

// Google Kickstart
int longestArithmeticSubarray(int arr[], int size){
    int ans = 2;
    int pd = arr[1]-arr[0];
    int curr = 2;

    for (int i = 2; i < size; i++)
    {
        if(pd == arr[i]-arr[i-1]){curr++;}
        else{pd = arr[i] - arr[i-1]; curr = 2;}
        ans = max(ans,curr);
    }

    return ans;
}

// Google Kickstart
int numberOfRecordBreakingDays(int arr[], int size){
    int ans = 0;
    int mx = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]>mx && arr[i]>arr[i+1]) ans++;
        mx = max(mx, arr[i]);
    }
    
    return ans;
}

void solve(){
    // int arr[6] = {0,-9,1,3,-4,5};
    // maxTillI(arr,6);

    // int arr[] = {1,2,0,7,2};
    // sumOfAllSubarrays(arr,5);

    // int arr[] = {10,7,4,6,8,10,11};
    // cout<<longestArithmeticSubarray(arr,7);

    int arr[] = {1,2,0,7,2,0,2,2,-1};
    cout<<numberOfRecordBreakingDays(arr,9);
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
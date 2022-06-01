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

void printSubArrays(int arr[], int size){
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j <= size; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

// Brute Force O(n^3) 
// int maxSumOfSubArrays(int arr[], int size){
//     int mx = INT_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             int sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += arr[k];
//             }

//             mx = max(mx, sum);
//         }
//     }

//     return mx;
// }

// Cumulative sum approach O(n^2)
// int maxSumOfSubArrays(int arr[], int size){
//     vector<int> currsum;
//     currsum.push_back(0);

//     for (int i = 0; i < size; i++)
//     {
//         currsum.push_back(currsum[i] + arr[i]);
//     }
    
//     int mx = INT_MIN;
//     for (int i = 1; i <= size; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < i; j++)
//         {
//             sum = currsum[i] - currsum[j];
//             mx = max(mx, sum);
//         }
//     }
//     return mx;
// }

// Kadane's Algorithm O(n)
int maxSumOfSubArrays(int arr[], int size){
    int currsum = 0;
    int mx = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        currsum += arr[i];
        if(currsum<0) currsum=0;
        mx = max(mx, currsum);
    }

    return mx;
}

// Max subarray sum = Total sum of array - Sum of non-contributing elements 
int maxCircularSubarraySum(int arr[], int size){
    int currsum = 0;
    int mx = INT_MIN;

    int totalSum = 0;
    for (int i = 0; i < size; i++)
    {
        totalSum += arr[i];
    }
    
    // revercing signs of elements of array 
    for (int i = 0; i < size; i++)
    {
        arr[i] = -arr[i];
    }

    int sumOfNonContributingElements = -maxSumOfSubArrays(arr,size);
    // cout<<totalSum<<" "<<sumOfNonContributingElements<<endl;
    int ans = totalSum - sumOfNonContributingElements;
    return ans;
}

bool pairSum(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;

    while (j > i)
    {
        int sum = arr[i] + arr[j];
        if(sum > k) {j--;}
        else if (sum < k) {i++;}
        else {return 1;}
    }

    return 0;
}

void solve(){
    // int arr[7] = {4,-4,6,-6,10,-11,12};
    // printSubArrays(arr, 4);
    // cout<<maxSumOfSubArrays(arr, 4)<<endl;
    // cout<<maxCircularSubarraySum(arr,7);
    
    vector<int> arr = {4,-4,6,-6,10,-11,12};
    cout<<pairSum(arr, 3);
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
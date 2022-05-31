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

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int size){
    int tmp;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[i]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            } else{
                continue;
            }
        }
    }

    cout<<"Selection Sort: ";
    printArray(arr,10);
}

void bubbleSort(int arr[], int size){
    int tmp;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
             if(arr[j] > arr[j+1]){
                 tmp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = tmp;
             }
        }
    }

    cout<<"Bubble Sort: ";
    printArray(arr,10);
}

void insertionSort(int arr[], int size){
    int tmp;
    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j = i-1;
        while (arr[j] > cur && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = cur;
    }

    cout<<"Insertion Sort: ";
    printArray(arr,10);
}

void solve(){
    int arr[10] = {7,45,-2,4,68,10,12,-7,2,0};
    cout<<"Original Array: ";
    printArray(arr,10);

    // selectionSort(arr,10);
    // bubbleSort(arr,10);
    insertionSort(arr,10);
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
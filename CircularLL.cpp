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

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL) {n->next = n; head=n; return;}
    node* tmp = head;
    while (tmp->next != head) tmp = tmp->next;
    tmp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL) {insertAtHead(head, val); return;}
    node* tmp = head;
    while (tmp->next != head) tmp = tmp->next;
    tmp->next = n;
    n->next = head;
}

void display(node* head){
    node* tmp = head;
    do
    {
        cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    } while(tmp != head);
 
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* tmp = head;
    do
    {
        if(tmp->data == key) return true;
        tmp = tmp->next;
    } while(tmp != head);
    return false;
}

void deleteAtHead(node* &head){
    node* tmp = head;
    while(tmp->next != head) tmp = tmp->next;
    node* todel = head;

    tmp->next = head->next;
    head = head->next;
    delete todel;
}

void deletion(node* &head, int val){

    if(head == NULL) return;
    if(val == 1) {deleteAtHead(head); return;}

    node* tmp = head;
    int count = 1;

    while (count != val-1){
        tmp = tmp->next;
        count++;
    }

    node* todel = tmp->next;
    tmp->next = tmp->next->next;
    delete todel;
}

int leangth(node* head){
    int l  = 0; node* tmp = head;
    do {l++; tmp = tmp->next;} while(tmp != head);
    return l;
}

void solve(){
    node* head1 = NULL;
    node* head2 = NULL;

    v32 arr1 = {1,2,3,4,5,6};
    v32 arr2 = {9, 10};
    forn(i, arr1.size()) insertAtTail(head1, arr1[i]);
    forn(i, arr2.size()) insertAtTail(head2, arr2[i]);

    display(head1);
    insertAtHead(head1, 9);
    deletion(head1, 5);
    display(head1);
    deletion(head1, 1);
    display(head1);
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
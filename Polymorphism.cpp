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

class Circle{
    int radius;
    
    public:
    Circle(){cout<<"Default Costructor"<<endl;}
    Circle(int r){radius = r;}
    void setRadius(int r){radius = r;}
    void setRadius(double r){cout<<"Double Overload";}
    int getRadius(){return radius;}
    double getArea(){return  3.14*pow(radius, 2);}

    Circle operator + (Circle const &obj){
        Circle res;
        res.radius = radius + obj.radius;
        return res;
    }
};

class base {
    public:
    virtual void print(){cout<<"This is base class print"<<ln;}
    void display(){cout<<"This is base class display"<<ln;}
};

class derived : public base {
    public:
    void print(){cout<<"This is derived class print"<<ln;}
    void display(){cout<<"This is derived class display"<<ln;}
};

void solve(){
    // Circle c(2);
    // Circle d(3);
    // // cout<<c.getRadius()<<ln;
    // // cout<<c.getArea()<<ln;
    // // c.setRadius(3);
    // // cout<<c.getRadius()<<ln;
    // // c.setRadius(3.25);
    // cout<<c.getRadius()<<ln;
    // cout<<d.getRadius()<<ln;

    // Circle e = c + d;
    // cout<<e.getRadius()<<ln;

    base *baseptr;
    derived d;
    baseptr = &d;

    baseptr -> print();
    baseptr -> display();
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
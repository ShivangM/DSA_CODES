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

void reverseSentence(string s){
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while ((!st.empty()))
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

void insertAtBottom(stack<int> &st, int ele){

    if(st.empty()){
        st.push(ele); return;
    }

    int topele = st.top(); st.pop();
    insertAtBottom(st , ele);

    st.push(topele);
}

void reverseStack(stack<int> &st){

    if(st.empty()) return;

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}

void printStack(stack<int> &st, int size){
    forn(i, size){ cout<<st.top()<<" "; st.pop(); }
    cout<<endl;
}

int prefixEvaluation(string s){
    stack<int> st;
    rforn(i, s.length()-1) 
    if(s[i] >= '0' && s[i] <= '9') st.push(s[i] - '0');
    else {
        int op1 = st.top(); st.pop();
        int op2 = st.top(); st.pop();

        switch (s[i])
        {
        case '+':
            st.push(op1+op2);
            break;
        case '-':
            st.push(op1-op2);
            break;
        case '*':
            st.push(op1*op2);
            break;
        case '/':
            st.push(op1/op2);
            break;
        case '^':
            st.push(pow(op1,op2));
            break;
        
        default:
            break;
        }
    }

    return st.top();
}

int postfixEvaluation(string s){
    stack<int> st;
    forn(i, s.length()) 
    if(s[i] >= '0' && s[i] <= '9') st.push(s[i] - '0');
    else {
        int op2 = st.top(); st.pop();
        int op1 = st.top(); st.pop();

        switch (s[i])
        {
        case '+':
            st.push(op1+op2);
            break;
        case '-':
            st.push(op1-op2);
            break;
        case '*':
            st.push(op1*op2);
            break;
        case '/':
            st.push(op1/op2);
            break;
        case '^':
            st.push(pow(op1,op2));
            break;
        
        default:
            break;
        }
    }

    return st.top();
}
 
int precidence(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '-' || c == '+') return 1;
    else return -2;
}

string infixToPostfix(string s){
    stack<char> st;
    string res = "";

    forn(i, s.length()){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i]>= 'A' && s[i] <= 'Z')){
            res += s[i];
        }
        else if(s[i] = '('){
            st.push(s[i]);
        }
        else if(s[i] = ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top(); st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while (!st.empty() && (precidence(st.top()) > precidence(s[i]))){
                res += st.top(); st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top(); st.pop();
    }
    return res;
}

void solve(){
    // string s = "Hey how are you doing?";
    // reverseSentence(s);

    // stack<int> st; 
    // forn(i, 4) st.push(i);

    // printStack(st, st.size());
    // reverseStack(st);
    // printStack(st, st.size());

    // cout<<prefixEvaluation("-+7*45+20")<<endl;
    // cout<<postfixEvaluation("46+2/5*7+")<<endl;
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
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
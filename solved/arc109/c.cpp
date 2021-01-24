#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

char winner(char a, char b){
    if(a == b)return a;
    if(a == 'R' && b == 'S')return a;
    if(a == 'S' && b == 'P')return a;
    if(a == 'P' && b == 'R')return a;
    return b;
}

char taur(string s){
    while(s.size() > 1){
        string n;
        rep(i,s.size()/2)n.push_back(winner(s[2*i], s[2*i+1]));
        s = n;
    }
    return s[0];
}
char winnern(char a, char b){
    if(a == b)return a;
    if(a == 'R' && b == 'S')return a;
    if(a == 'S' && b == 'P')return a;
    if(a == 'P' && b == 'R')return a;
    return b;
}

int main(){
    int n, k;
    string s, ss;
    cin >> n >> k >> s;
    if(k < 7){
        if(pow(2, k) < n){
            cout << taur(s.substr(0, pow(2,k))) << endl;
            return 0;
        }
    }
    int m = 0;
    while(pow(2,m) < n)++m;
    rep(i,1030)ss += s;
    ss += ss;
    string t;
    rep(i,k-m+1){
        t.push_back(taur(ss.substr(i, pow(2,m))));
    }
    cout << t << endl;
    cout << taur(t) << endl;
    return 0;
}

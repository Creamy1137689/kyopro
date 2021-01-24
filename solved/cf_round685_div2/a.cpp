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

ll solve(ll N){
    ll res = 0;
    if(N == 1)res = 0;
    else if(N == 2)res = 1;
    else if(N == 3)res =2;
    else if(N % 2 == 0)res = 2;
    else res = 3;
    return res;
}

int main(){
    int t;
    cin >> t;
    vector<ll> ns(t);
    rep(i,t)cin >> ns[i];
    rep(i,t)cout << solve(ns[i]) << endl;
    return 0;
}

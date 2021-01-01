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

void solve(int N){
    priority_queue<int> pq;
    REP(i,N)pq.push(i);
    vector<P> ans;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push((a+b)/2 + ((a+b) % 2 == 1));
        ans.push_back(make_pair(a,b));
    }
    cout << pq.top() << endl;
    for(auto x:ans)cout << x.first << ' ' << x.second << endl;
}

int main(){
    int t;
    cin >> t;
    vector<int> ns(t);
    rep(i,t)cin >> ns[i];
    rep(i,t)solve(ns[i]);
    return 0;
}

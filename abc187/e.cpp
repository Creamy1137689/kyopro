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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

typedef pair<int, pair<int,int>> pp;

int main(){
    int n;
    int a, b;
    int t, e, x;
    cin >> n;
    vector<vector<int>> G(n, vector<int>());
    vector<P> path(n-1);
    rep(i,n-1){
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
        path[i] = make_pair(a, b);
    }
    vector<map<int,int>> qr(n, map<int,int>());
    int q;
    cin >>q;
    rep(i, q){
        cin >> t >> e >> x;
        --e;
        if(t == 1){
            a = path[e].first;
            b = path[e].second;
            qr[a][b] += x;
        }else{
            a = path[e].first;
            b = path[e].second;
            qr[b][a] += x;
        }
    }
    queue<pair<int, pair<int,int>>> que;
    rep(i,n){
        if(G[i].size() == 1)que.push(make_pair(i, make_pair(0, inf)));
    }
    vector<ll> ans(n, 0);
    vector<set<int>> al(n);
    while(!que.empty()){
        pp v = que.front();
        int now = v.first;
        int cost = v.second.first;
        int from = v.second.second;
        que.pop();
        if(v.second.second != inf)al[v.first].insert(v.second.second);
        ans[v.first] += v.second.first;
        for(auto t:G[now]){
            if((al[now].count(t) == 0 && al[now].size() == G[now].size()-1) || al[now].size() == G[now].size()){
                int ncost = cost;
                for(auto y: qr[now]){
                    if(y.second != t)ncost += y.first;
                }
                que.push(make_pair(t, make_pair(ncost, now)));
            }
        }     
    }
    show(ans);
    return 0;
}

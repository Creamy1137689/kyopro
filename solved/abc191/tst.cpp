#include <bits/stdc++.h>
#include <atcoder/all>
#include <random>
using namespace std;
using namespace atcoder;

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

vector<vector<P>> G(2020, vector<P>());

void dijkstra(int s, vector<int>& dist){
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    while(!q.empty()){
        int cost = q.top().first;
        int f = q.top().second;
        q.pop();
        if(cost > dist[f])continue;
        for(auto t:G[f]){
            if(dist[t.first] > cost + t.second){
                dist[t.first] = cost + t.second;
                q.emplace(dist[t.first], t.first);
            }
        }
    }
}

int main(){
    random_device gen;
    mt19937_64 engine(gen());
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, a, b, c;
    n = 2000; m = 2000;
    rep(i,m){
        a = gen() % 2000 + 1;
        b = gen() % 2000 + 1;
        c = gen() % 100000 + 1;
        --a; --b;
        G[a].emplace_back(b, c);
    }
    rep(i,n){
        vector<int> dist(n, inf);
        dijkstra(i, dist);
        /* if(dist[i] == inf)cout << -1 << endl; */
        /* else cout << dist[i] << endl; */
    }
    cout << "END" << endl;
    return 0;
}


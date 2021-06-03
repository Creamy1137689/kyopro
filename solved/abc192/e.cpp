#include <bits/stdc++.h>
#include <atcoder/all>
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

struct dat{
    ll to, T, K;
};

vector<vector<dat>> G(100100, vector<dat>());

void dijkstra(int s, vector<ll>& dist){
    priority_queue<lp, vector<lp>, greater<lp>> q;
    q.emplace(0, s);
    dist[s] = 0;
    while(!q.empty()){
        ll cost = q.top().first;
        ll f = q.top().second;
        q.pop();
        if(cost > dist[f])continue;
        for(auto e:G[f]){
            ll to = e.to, t = e.T, k = e.K;
            ll nt = (cost / k + (cost % k != 0)) * k;
            if(dist[to] > t + nt){
                dist[to] = t + nt;
                q.emplace(dist[to], to);
            }
        }
    }
}

int main(){
    int n, m, x, y;
    int a, b, t, k;
    cin >> n >> m >> x >> y;
    --x; --y;
    rep(i,m){
        cin >> a >> b >> t >> k;
        --a; --b;
        G[a].push_back({b, t, k});
        G[b].push_back({a, t, k});
    }
    vector<ll> dist(n, INF);
    dijkstra(x, dist);
    ll ans = dist[y];
    if(ans == INF)ans = -1;
    cout << ans << endl;
    return 0;
}

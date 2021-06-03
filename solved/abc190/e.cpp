#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 0x3fffffff;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

void bfs(int s, vector<int>& dist, vector<vector<int>>& g){
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto t: g[f]){
            if(dist[t] == inf){
                dist[t] = dist[f]+1;
                q.push(t);
            }
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    vector<vector<int>> ng(k, vector<int>(k));
    rep(i,k)cin >> c[i];
    rep(i,k)c[i]--;
    rep(i,k){
        vector<int> dist(n, inf);
        bfs(c[i], dist, g);
        rep(j,k)ng[i][j] = dist[c[j]];
    }

    vector<vector<int>> dp(1<<k, vector<int>(k,inf));
    rep(i,k)dp[1<<i][i] = 1;
    for(int S = 1; S < (1<<k); ++S) rep(t,k) if(S & (1 << t)){
        int T = S-(1<<t);
        rep(f,k){
            if(T & (1<<f))chmin(dp[S][t], dp[T][f] + ng[f][t]);
        }
    }
    int ans = inf;
    rep(i,k)chmin(ans, dp[(1<<k)-1][i]);
    if(ans == inf)ans = -1;
    cout << ans << endl;
    return 0;
}

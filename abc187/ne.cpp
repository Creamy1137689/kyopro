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

void dfs(int v, vector<int>& depth, vector<vector<int>>& G){
    for(auto x:G[v]){
        if(depth[x] == inf){
            depth[x] = depth[v] + 1;
            dfs(x, depth, G);
        }
    }
}

void dfs2(int v, vector<ll>& c, vector<bool>& vis, vector<vector<int>>& G){
    for(auto x:G[v]){
        if(!vis[x]){
            c[x] += c[v];
            vis[x] = true;
            dfs2(x, c, vis, G);
        }
    }
}

int main(){
    int n;
    int a, b;
    int t, e, x;
    cin >> n;
    vector<P> path(n-1);
    vector<vector<int>> G(n, vector<int>());
    rep(i,n-1){
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
        path[i] = make_pair(a, b);
    }
    vector<int> depth(n, inf);
    depth[0] = 0;
    dfs(0, depth, G);
    int q;
    cin >> q;
    vector<ll> c(n, 0);
    rep(i, q){
        cin >> t >> e >> x;
        --e;
        a = path[e].first;
        b = path[e].second;
        if(t == 1){
            if(depth[a] < depth[b]){
                c[0] += x;
                swap(a, b);
                x *= -1;
            }
            c[a] += x;
        }else{
            if(depth[a] > depth[b]){
                c[0] += x;
                swap(a, b);
                x *= -1;
            }
            c[b] += x;
        }
    }
    vector<bool> vis(n, false);
    vis[0] = true;
    dfs2(0, c, vis, G);
    show(c);
    return 0;
}

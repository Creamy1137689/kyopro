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

void bfs(int s, vector<int> &dist, vector<vector<int>> &G){
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto t:G[f]){
            if(dist[t] == inf){
                dist[t] = dist[f]+1;
                q.push(t);
            }
        }
    }
}

int main(){
    int N, x, y;
    cin >> N >> x >> y;
    --x; --y;
    vector<vector<int>> G(N, vector<int>());
    rep(i,N-1){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);
    vector<int> ans(N-1, 0);
    rep(i,N){
        vector<int> dist(N, inf);
        bfs(i, dist, G);
        rep(j,N){
            if(i == j)continue;
            ans[dist[j]-1]++;
        }
    }
    rep(i,N-1)ans[i] /= 2;
    show(ans);
    return 0;
}

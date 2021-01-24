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
const int MOD = (int)(1e9) + 7;

vector<vector<int>> G(110, vector<int>(110, inf));

void dijkstra(int start, vector<int> &dist){
	priority_queue<P, vector<P>, greater<P>> Q;
	Q.emplace(0, start);
	dist[start] = 0;
	while(!Q.empty()){
		int cost = Q.top().first;
		int f = Q.top().second;
		Q.pop();
		if(cost > dist[f])continue;
        rep(t,110){
            if(G[f][t] == inf)continue;
            if(dist[t] > G[f][t] + cost){
                dist[t] = cost + G[f][t];
                Q.emplace(dist[t], t);
            }
        }
	}
}

int main(){
    int N, K, com, a, b, c, d, e;
    cin >> N >> K;
    rep(i,K){
        cin >> com;
        if(com == 0){
            cin >> a >> b;
            --a; --b;
            vector<int> dist(110,inf);
            dijkstra(a, dist);
            int res = dist[b];
            if(res == inf)res = -1;
            cout << res << endl;
        }else{
            cin >> c >> d >> e;
            --c; --d;
            G[c][d] = min(G[c][d], e);
            G[d][c] = min(G[d][c], e);
        }
    }
    return 0;
}

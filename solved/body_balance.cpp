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

int N, M, s, t, x, y, d;
vector<vector<P>> G(1010, vector<P>());

void dijkstra(int start, vector<int> &dist){
	priority_queue<P, vector<P>, greater<P>> Q;
	Q.emplace(0, start);
	dist[start] = 0;
	while(!Q.empty()){
		int cost = Q.top().first;
		int f = Q.top().second;
		Q.pop();
		if(cost > dist[f])continue;
		for(auto t:G[f]){
			if(dist[t.first] > cost + t.second){
				dist[t.first] = cost + t.second;
				Q.emplace(dist[t.first], t.first);
			}
		}
	}
}

int main(){
	cin >> N >> M >> s >> t;
	--s; --t;
	rep(i,M){
		cin >> x >> y >> d;
		--x; --y;
		G[x].push_back(make_pair(y, d));
		G[y].push_back(make_pair(x, d));
	}
	vector<int> dist_from_s(N, inf);
	vector<int> dist_from_t(N, inf);
	dijkstra(s, dist_from_s);
	dijkstra(t, dist_from_t);
	rep(i,N){
		if(dist_from_s[i] == dist_from_t[i] && dist_from_s[i] != inf){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

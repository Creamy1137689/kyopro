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

vector<vector<P>> G(100100, vector<P>());

void dfs(int f, vector<int> &dist){
	for(auto x:G[f]){
		if(dist[x.first] == inf){
			dist[x.first] = dist[f] + x.second;
			dfs(x.first, dist);
		}
	}
}

int main(){
	int N, M, l, r, d;
	cin >> N >> M;
	vector<tuple<int,int,int>> edge(M);
	rep(i,M){
		cin >> l >> r >> d;
		--r; --l;
		edge[i] = make_tuple(l, r, d);
		G[r].push_back(make_pair(l,-d));
		G[l].push_back(make_pair(r,d));
	}
	vector<int> dist(N,inf);
	rep(i,N){
		if(dist[i] == inf){dist[i] = 0; dfs(i, dist);}
	}
	bool ans = true;
	rep(i,M){
		if(dist[get<1>(edge[i])] - dist[get<0>(edge[i])] != get<2>(edge[i]))ans = false;
	}
	cout << ((ans) ? "Yes" : "No") << endl;
	return 0;
}

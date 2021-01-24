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


int main(){
	int N, x, a, b;
	cin >> N >> x;
	--x;
	vector<vector<int>> G(N, vector<int>());
	vector<int> is_jewel(N);
	vector<bool> route(N-1, false);
	map<P, int> path;
	rep(i,N)cin >> is_jewel[i];
	rep(i,N-1){
		cin >> a >> b;
		--a; --b;
		if(a > b)swap(a,b);
		G[a].push_back(b);
		G[b].push_back(a);
		path[make_pair(a,b)] = i;
	}
	vector<int> dist(N, inf);
	queue<int> Q;
	Q.push(x);
	dist[x] = 0;
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto x:G[f]){
			if(dist[x] == inf){
				dist[x] = dist[f] + 1;
				Q.push(x);
			}
		}
	}
	rep(i,N){
		if(is_jewel[i] == 1){
			int d = dist[i];
			int v = i;
			while(d > 0){
				for(auto x:G[v]){
					if(dist[x] + 1 == d){
						--d;
						int a = v, b = x;
						if(a > b)swap(a,b);
						route[path[make_pair(a,b)]] = true;
						v = x;
						continue;
					}
				}
			}
		}
	}
	int ans = 0;
	rep(i,N-1)if(route[i])++ans;
	cout << ans * 2 << endl;
	return 0;
}

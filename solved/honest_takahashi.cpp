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
	int N, s, distination, M, x, y;
	cin >> N >> s >> distination >> M;
	vector<vector<int>> G(N, vector<int>());
	rep(i,M){
		cin >> x >> y;
		--x; --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	--s; --distination;
	vector<int> ans(N, 0);
	vector<int> dist(N, inf);
	queue<int> Q;
	ans[s] = 1;
	dist[s] = 0;
	Q.push(s);
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto t:G[f]){
			if(dist[t] == inf){
				dist[t] = dist[f] + 1;
				ans[t] = ans[f];
				Q.push(t);
			}else if(dist[t] == dist[f] + 1){
				ans[t] += ans[f];
				ans[t] %= MOD;
			}
		}
	}
	cout << ans[distination] << endl;;
	return 0;
}

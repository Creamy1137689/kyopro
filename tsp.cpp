#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <cstring>
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
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int V,E; 
int path[17][17];
int dp[1<<17][17];

// int solve(int S, int v){
// 	if(dp[S][v]>=0) return dp[S][v];
// 	if(S == (1<<V)-1 && v == 0) return dp[S][v] = 0;
// 	int res = inf;
// 	for(int u = 0; u<V; u++){
// 		if(!(S>>u & 1)){ //まだ行っていないところがあったら，そこへ行ってみる
// 			res = min(res, solve(S | 1<<u, u) + path[v][u]);
// 		}
// 	}
// 	return dp[S][v] = res;
// }

// int main(){
// 	cin>>V>>E;
// 	rep(i,V)rep(j,V)path[i][j] = inf;
// 	rep(i,E){
// 		int s,t,d; cin>>s>>t>>d;
// 		path[s][t] = d;
// 	}
// 	memset(dp, -1, sizeof(dp));
// 	int ans = solve(0,0);
// 	if(ans == inf)ans = -1;
// 	cout<<ans<<endl;
// 	return 0;
// }

int main(){
	cin>>V>>E;
	rep(i,V)rep(j,V)path[i][j] = inf;
	rep(i,E){
		int s,t,d; cin>>s>>t>>d;
		path[s][t] = d;
	}
	rep(i,1<<V)rep(j,V)dp[i][j] = inf;
	dp[(1<<V)-1][0] = 0;
	for(int S = (1<<V)-2; S>=0; S--){
		for(int v = 0; v<V; v++){
			for(int u = 0; u<V; u++){
				if(!(S>>u & 1)){
					dp[S][v] = min(dp[S][v], dp[S|(1<<u)][u] + path[v][u]);
				}
			}
		}
	}
	int ans = dp[0][0];
	if(ans == inf)ans = -1;
	cout<<ans<<endl;
}
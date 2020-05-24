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
#define show(obj) {for(auto x:obj)cout<<x.first<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int N,M;
const int MAX_N = 20;
ll tim[20][20];
ll dis[20][20];

int main(){
	cin>>N>>M;
	rep(i,MAX_N){
		rep(j,MAX_N){
			dis[i][j] = inf;
			tim[i][j] = -1;
		}
	}
	rep(i,M){
		ll s,t,d,T;
		cin>>s>>t>>d>>T;
		s--; t--;
		dis[s][t] = d;	dis[t][s] = d;
		tim[s][t] = T;	tim[t][s] = T;
	}
	vector<vector<lp>> dp((1<<N), vector<lp> (N, make_pair(INF,0)));
	dp[0][0] = make_pair(0LL, 1LL);
	for(int S = 1; S<(1<<N); ++S){
		for(int v = 0; v<N; ++v){
			if(!(S & (1<<v)))continue;
			for(int u = 0; u<N; ++u){
				if(dis[v][u] == inf)continue;
				ll cost = dp[S & ~(1<<v)][v].first + dis[v][u];
				if(cost > tim[v][u])continue;
				if(cost < dp[S][u].first)dp[S][u] = make_pair(cost, 0);
				if(cost == dp[S][u].first)dp[S][u].second += dp[S & ~(1<<v)][v].second;
			}
		}
	}
	ll ans_a = dp[(1<<N)-1][0].first, ans_b = dp[(1<<N)-1][0].second;
	if(ans_b){
		cout<<ans_a<<' '<<ans_b<<endl;
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
	// vector<vector<ll>> dp((1<<N)+1, vector<ll> (N+1,INF));
	// dp[0][0] = 0LL;
	// for(int S = 0; S<=(N<<1); ++S){
	// 	for(int v = 0; v<=N; ++v){
	// 		for(int u = 0; u<=N; ++u){
	// 			if(!(S>>u & 1) && dp[S][v] <= tim[u]){
	// 				chmin(dp[S|(1<<u)][u], dp[S][v] + dis[v][u]);
	// 			}
	// 		}
	// 	}
	// }
	// rep(i,(1<<N))show(dp[i]);
	// ll ans = dp[(1<<N)-1][0];
	// if(ans == INF)cout<<"IMPOSSIBLE"<<endl;
	// else cout<<ans<<endl;
	// return 0;
}


// 0                    1152921504606846976 1152921504606846976 
// 1001001000           1152921504606846976 1152921504606846976 
// 1152921504606846976  1                   1152921504606846976 
// 2                    1152921504606846976 1152921504606846976 
// 1152921504606846976  1152921504606846976 3 
// 6                    1152921504606846976 1152921504606846976 
// 1152921504606846976  5                   3 
// 1152921504606846976  7                   5 

// 0                     1152921504606846976 1152921504606846976 1152921504606846976 
// 1001001000            1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976   1                   1152921504606846976 1152921504606846976 
// 2                     1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976   1152921504606846976 3                   1152921504606846976 
// 6                     1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976   5                   3                   1152921504606846976 
// 6                     7                   5                   1152921504606846976 

// 0                      1152921504606846976 1152921504606846976 1152921504606846976 
// 1001001000             1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976    1                   1152921504606846976 1152921504606846976 
// 2                      1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976    1152921504606846976 1                   1152921504606846976 
// 2                      1152921504606846976 1152921504606846976 1152921504606846976 
// 1152921504606846976    2                   2                   1152921504606846976 
// 1152921504606846976    3                   3                   1152921504606846976 
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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	ll H,N; cin>>H>>N;
	ll max_dam = 123456;
	vector<lp> magic(N);
	rep(i,N)cin>>magic[i].first>>magic[i].second;
	vector<vector<ll>> dp(N+1, vector<ll> (max_dam+1,INF));
	rep(i,N+1)dp[i][0] = 0;
	REP(i,N){
		REP(j,max_dam){
			ll item_num = i-1;
			chmin(dp[i][j], dp[i-1][j]);
			if(j<magic[item_num].first)continue;
			chmin(dp[i][j], dp[i][j-magic[item_num].first] + magic[item_num].second);
		}
	}
	ll ans = INF;
	// rep(i,N+1){
	// 	rep(j,10){
	// 		int t;
	// 		if(dp[i][j] == INF)t = -1;
	// 		else t = dp[i][j];
	// 		printf("%3d ",t);
	// 	}
	// 	cout<<endl;
	// }
	for(ll i = H; i<=max_dam; ++i)chmin(ans, dp[N][i]);
	cout<<ans<<endl;
	return 0;
}
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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}


int main(){
	int N,M; cin>>N>>M;
	vector<ll> a(M), b(M), c(M,0);
	rep(i,M){
		cin>>a[i]>>b[i];
		rep(j,b[i]){
			int t; cin>>t; --t;
			c[i] += (1<<t);
		}
	}

	vector<vector<ll>> dp(1010, vector<ll>(5050,inf));
	dp[0][0] = 0;

	rep(i,M){
		rep(j,(1<<N)){
			chmin(dp[i+1][j], dp[i][j]);
			int nj = j | c[i];
			chmin(dp[i+1][nj], dp[i][j] + a[i]);
		}
	}
	int ans = dp[M][(1<<N)-1];
	if(ans == inf){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}

// int main(){
// 	int N,M;
// 	cin>>N>>M;
// 	vector<ip> key(M+1); // based-on-10, value
// 	REP(i,M){
// 		int a,b;
// 		cin>>a>>b;
// 		key[i].second = a;
// 		int sum = 0;
// 		rep(j,b){
// 			int t; cin>>t;
// 			sum += pow(2,t-1);
// 		}
// 		key[i].first = sum;
// 	}
// 	//sort(all(key));
// 	vector<vector<int>> dp(1010, vector<int> (1030, inf));
// 	rep(i, M+1)dp[i][0] = 0;
// 	REP(i,M){
// 		for(int j = 1; j<(1<<N); ++j){
// 			chmin(dp[i][j], dp[i-1][j]);
// 			if(j & key[i].first){
// 				chmin(dp[i][j], dp[i-1][max(0,j-(j & key[i].first))] + key[i].second);
// 			}
// 		}
// 	}
// 	// rep(i,M+1){rep(j,(1<<N))cout<<dp[i][j]<<' ';cout<<endl;}
// 	int ans = dp[M][(1<<N)-1];
// 	if(ans == inf){
// 		cout<<-1<<endl;
// 	}else{
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }
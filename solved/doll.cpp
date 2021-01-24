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
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N,M; cin>>N>>M;
	vector<vector<int>> toy(M,vector<int> (N+1,0));
	REP(i,N){
		int t; cin>>t;
		++toy[--t][i];
	}
	rep(i,M){
		rep(j,N){
			toy[i][j+1] += toy[i][j];
		}
	}
	vector<int> siz(M,0);
	rep(i,M)siz[i] = toy[i][N];	vector<int> dp((1<<M), inf);
	dp[0] = 0;
	for(int S = 0; S<(1<<M); ++S){
		int cnt = 0;
		rep(it,M)if(S&(1<<it))cnt += siz[it];
		rep(it,M){
			if(S & (1<<it))continue;
			chmin(dp[S | (1<<it)], dp[S] + siz[it] - toy[it][cnt+siz[it]] + toy[it][cnt]);
			// int range = toy[it][N-1];
			// int st = dp[S&~(1<<it)].second;
			// int cnt = toy[it][st+range]-toy[it][st];
			// if(chmin(dp[S].first, dp[S&~(1<<it)].first + range - cnt)){
			// 	dp[S].second = dp[S&~(1<<it)].second + range;
			// }
		}
	}
	// show(dp);
	cout<<dp[(1<<M)-1]<<endl;
	return 0;
}
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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N, L, rt, jt, pt; cin>>N>>L;
	vector<bool> hardor(L+1,false);
	rep(i,N){
		int t; cin>>t;
		hardor[t] = true;
	}
	cin>>rt>>jt>>pt;
	vector<vector<int>> dp(L+1, vector<int>(3, inf));
	dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
	REP(i,L){
		rep(j,3)chmin(dp[i][0], dp[i-1][j] + rt);
		if(i>=2){
			rep(j,3)chmin(dp[i][1], dp[i-2][j] + rt + jt);
		}
		if(i>=4){
			rep(j,3)chmin(dp[i][2], dp[i-4][j] + rt + jt*3);
		}
		if(hardor[i]){
			rep(j,3)dp[i][j] += pt;
		}
	}
	int ans = inf;
	rep(i,3){chmin(ans, dp[L][i]);}
	if(L>=1)rep(i,3){chmin(ans, dp[L-1][i] + rt/2 + jt/2) ;}
	if(L>=2)rep(i,3){chmin(ans, dp[L-2][i] + rt/2 + jt/2*3) ;}
	if(L>=3)rep(i,3){chmin(ans, dp[L-3][i] + rt/2 + jt/2*5) ;}
	cout<<ans<<endl;
	return 0;
}
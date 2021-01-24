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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> coin(m);
	rep(i,m)cin>>coin[i];
	sort(all(coin));
	vector<vector<int>> dp(m+1, vector<int>(n+1,inf));
	rep(i,m+1)dp[i][0] = 0;
	for(int i = 1; i<=m; ++i){
		for(int j = 1; j<=n; ++j){
			if(coin[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				chmin(dp[i][j], dp[i-1][j]);
				chmin(dp[i][j], dp[i][j-coin[i-1]]+1);
			}
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}

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

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int main(){
	int N,W;
	cin>>N>>W;
	vector<ip> item(N);
	rep(i,N)cin>>item[i].first>>item[i].second;
	vector<vector<int>> dp(N+1, vector<int> (W+1, 0));
	for(int i = N-1; i>=0; --i){
		for(int j = 1; j<=W; ++j){
			if(item[i].second > j){
				dp[i][j] = dp[i+1][j];
			}else{
				chmax(dp[i][j], dp[i+1][j]);
				chmax(dp[i][j], dp[i][j-item[i].second] + item[i].first);
			}
		}
	}
	cout<<dp[0][W]<<endl;
	return 0;
}
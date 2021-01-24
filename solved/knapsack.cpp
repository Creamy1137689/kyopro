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
	vector<vector<ll>> dp(N+1, vector<ll> (W+1, 0LL));
	cout<<"get"<<endl;
	for(int i = 1; i<=N; ++i){
		for(int j = 0; j<=W; ++j){
			if(item[i-1].second > j){
				dp[i][j] = dp[i-1][j];
			}else{
				chmax(dp[i][j], dp[i-1][j-item[i-1].second] + item[i-1].first);
				chmax(dp[i][j], dp[i-1][j]);
			}	
		}
	}
	cout<<dp[N][W]<<endl;
	return 0;
}
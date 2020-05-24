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

int N,M;
vector<ll> dis(1010);
vector<ll> wea(1010);
vector<vector<ll>> dp(1010, vector<ll> (1010, INF));

int main(){
	cin>>N>>M;
	REP(i,N)cin>>dis[i];
	REP(i,M)cin>>wea[i];
	rep(i,M+1)dp[i][0] = 0LL; 
	REP(i,M){
		REP(j,N){
			chmin(dp[i][j], dp[i-1][j]);
			chmin(dp[i][j], dp[i-1][j-1] + dis[j]*wea[i]);
		}
	}
	cout<<dp[M][N]<<endl;
	return 0;
}
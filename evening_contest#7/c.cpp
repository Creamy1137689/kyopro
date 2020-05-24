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

int main(){
	int N,M;
	cin>>N>>M;
	vector<int> dp(N+1,0);
	rep(i,M){
		int t;
		cin>>t;
		dp[t] = -1;
	}
	dp[0] = 1; dp[1] = ((dp[1]==-1)?0:1);
	for(int i = 2; i<=N ; ++i){
		if(dp[i] == -1)continue;
		int b1 = ((dp[i-1] == -1)?0:dp[i-1]);
		int b2 = ((dp[i-2] == -1)?0:dp[i-2]);
		dp[i] = b1 + b2;
		dp[i] %= MOD;
	}
	cout<<dp[N]<<endl;
	return 0;
}
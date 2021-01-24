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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N;
	cin >> N;
	vector<ll> dp(max(N+1, 5), 0);
	dp[0] = 1; dp[1] = 4; dp[2] = 16; dp[3] = 61; dp[4] = 230;
	for(int i = 5; i <= N; ++i){
		dp[i] += dp[i-1]*4; dp[i] %= MOD;
		dp[i] -= dp[i-3]*3; dp[i] %= MOD;
		dp[i] -= dp[i-4]*2; dp[i] %= MOD;
	}
	if(dp[N] < 0)dp[N] += MOD;
	cout << dp[N] << endl;
	return 0;
}

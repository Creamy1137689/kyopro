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

//int main(){
//	int N;
//	cin >> N;
//	vector<ll> dp(max(N+1, 5), 0);
//	dp[0] = 1; dp[1] = 4; dp[2] = 16; dp[3] = 61;
//	for(int i = 4; i <= N; ++i){
//		dp[i] += dp[i-1]*4; dp[i] %= MOD;
//		dp[i] -= dp[i-3]*2; dp[i] %= MOD;
//		dp[i] -= dp[i-4]*6; dp[i] %= MOD;
//		if(i >= 5){dp[i] += dp[i-5]; dp[i] %= MOD;}
//		if(i >= 6){dp[i] += dp[i-6]*2; dp[i] %= MOD;}
//	}
//	if(dp[N] < 0)dp[N] += MOD;
//	cout << dp[N] << endl;
//	return 0;
//}
int N;
map<pair<string, int>, ll> memo;
char tail[4] = {'A', 'C', 'G', 'T'};

bool check(string k){
	string t1 = k.substr(1,3);
	if(t1 == "AGC" || t1 == "ACG" || t1 == "GAC" || (k[0] == 'A' && (k[1] == 'G' || k[2] == 'G') && k[3] == 'C'))return false;
	return true;
}

ll dfs(string distn, int pos){
	if(memo.count(make_pair(distn, pos)) == 1)return memo[make_pair(distn, pos)];
	if(pos == N)return 1;
	ll res = 0;
	rep(i,4){
		string now = distn + tail[i];
		if(check(now)){
			res += dfs(now.substr(1, 3), pos + 1);
			res %= MOD;
		}
	}
	return memo[make_pair(distn, pos)] = res;
}

int main(){
	cin >> N;
	cout << dfs("TTT", 0) << endl;
}

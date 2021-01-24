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
	string s;
	cin >> s;
	ll dp[100100][2] = {0};
	dp[0][0] = 1;
	rep(i,s.size())rep(k,2){
		int nd = s[i] - '0';
		rep(d, 3){
			int ni = i + 1, nk = k;
			int el_sum = (d > 0);
			if(k == 0){
				if(el_sum > nd)continue;
				if(el_sum < nd)nk = 1;
			}
			dp[ni][nk] += dp[i][k];
			dp[ni][nk] %= MOD;
		}
	}
	ll ans = dp[s.size()][0] + dp[s.size()][1];
	ans %= MOD;
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}

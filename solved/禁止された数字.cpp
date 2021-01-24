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

ll digit_dp(string s){
	ll dp[20][20][2] = {0};
	int N = s.size();
	dp[0][0][0] = 1;
	rep(i,N)rep(j,20)rep(k,2){
		int nd = s[i] - '0';
		rep(d, 10){
			int ni = i + 1, nj = j, nk = k;
			if(d == 4 || d == 9) ++nj;
			if(k == 0){
				if(d > nd)continue;
				if(d < nd)nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	return dp[N][0][1] + dp[N][0][0];
}

int main(){
	string a, b;
	cin >> a >> b;
	ll t = stoll(a.c_str());
	--t;
	a = to_string(t);
	ll ans = stoll(b.c_str()) - stoll(a.c_str());
	ans -= digit_dp(b) - digit_dp(a);
	cout << ans << endl;
	return 0;
}

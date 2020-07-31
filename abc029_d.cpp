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

ll dp[11][11][2];

int main(){
	string s;
	cin >> s;
	int N = s.size();
	dp[0][0][0] = 1;
	rep(i,N)rep(j,11)rep(k,2){
		int nd = s[i] - '0';
		rep(d,10){
			int ni = i+1, nj = j, nk = k;
			if(d == 1) ++nj;
			if(k == 0){
				if(nd < d)continue;
				if(nd > d)nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	ll ans = 0;
	rep(j,11){
		ans += j*(dp[N][j][0] + dp[N][j][1]);
	}
	cout << ans << endl;
	return 0;
}

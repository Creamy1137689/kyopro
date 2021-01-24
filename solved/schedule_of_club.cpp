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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N; cin>>N;
	vector<int> resp(N+1);
	REP(i,N){
		char c; cin>>c;
		if(c == 'J')resp[i] = 0;
		if(c == 'O')resp[i] = 1;
		if(c == 'I')resp[i] = 2;
	}
	vector<vector<int>> dp(N+1, vector<int>(8, 0));
	dp[0][1] = 1;
	REP(i,N){
		REP(t, 7){
			if(!(t & (1<<resp[i])))continue;
			REP(y, 7){
				if(t & y){
					dp[i][t] += dp[i-1][y];
					dp[i][t] %= 10007;
				}
			}
		}
	}
	int ans = 0;
	REP(i,7)ans += dp[N][i];
	cout<<ans%10007<<endl;
	return 0;
}
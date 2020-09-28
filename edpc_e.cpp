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

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N, W;
	cin >> N >> W;
	vector<P> item(N);
	rep(i,N)cin >> item[i].first >> item[i].second;
	vector<vector<ll>> dp(N+1, vector<ll>(100100, INF));
	rep(i, N+1)dp[i][0] = 0;
	REP(i,N){
		REP(j,100100){
			chmin(dp[i][j], dp[i-1][j]);
			if(j-item[i-1].second >= 0)chmin(dp[i][j], dp[i-1][j-item[i-1].second] + item[i-1].first);	
		}
	}
	for(int i = 100000; i >= 0; --i){
		if(dp[N][i] <= W){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}

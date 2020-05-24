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
	int N,P; cin>>N>>P;
	vector<int> A(N);
	int nax= 0;
	rep(i,N){
		cin>>A[i];
		A[i] %= 2;
	}
	vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
	dp[0][0] = 1; dp[0][1] = 0;
	rep(i,N){
		if(A[i]==0){
			dp[i+1][0] = dp[i][0]*2;
			dp[i+1][1] = dp[i][1]*2;
		}else{
			dp[i+1][0] = dp[i][0] + dp[i][1];
			dp[i+1][1] = dp[i][0] + dp[i][1];
		}
	}
	cout<<dp[N][P]<<endl;
	return 0;
}
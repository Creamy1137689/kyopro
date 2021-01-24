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

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N;cin>>N;
	vector<int> slime(N);
	rep(i,N)cin>>slime[i];
	vector<vector<ll>> dp(N,vector<ll> (N,INF));
	vector<vector<ll>> cost(N,vector<ll> (N,INF));
	rep(i, N)cost[i][i] = slime[i];
	for(int i = 1; i<N; ++i){
		int l = 0, r = i;
		for(int _ = 0; _<N-i; ++_){
			for(int k = l; k<r; ++k){
				chmin(cost[l][r], cost[l][k] + cost[k+1][r]);
			}
			++l; ++r;
		}
	}
	rep(i,N)dp[i][i] = 0;
	for(int i = 1; i<N; ++i){
		int l = 0, r = i;
		for(int _ = 0; _<N-i; ++_){
			for(int k = l; k<r; ++k){
				chmin(dp[l][r], dp[l][k] + dp[k+1][r] + cost[l][r]);
			}
			++l; ++r;
		}
	}
	cout<<dp[0][N-1]<<endl;
	return 0;
}
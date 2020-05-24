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

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N;
	char nap[6][1005];
	vector<vector<int>> dp(3,vector<int>(1004,inf));
	char opt[3] = {'R','B','W'};
	cin>>N;
	REP(i,5)REP(j,N){
		cin>>nap[i][j];
	}
	rep(i,3)dp[i][0] = 0;
	REP(i,N){
		rep(j,3){
			int addi = 0;
			REP(l,5){
				if(nap[l][i] != opt[j])addi++;
			}
			//cout<<addi<<endl;
			rep(k,3){
				if(j==k)continue;
				chmin(dp[j][i], dp[k][i-1]+addi);
			}
		}
	}
	cout<<min({dp[0][N],dp[1][N], dp[2][N]})<<endl;
	return 0;
}
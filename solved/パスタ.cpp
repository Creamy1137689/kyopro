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

int dp[110][4][4];
int sche[110] = {0};

int main(){
	int n,k;
	cin>>n>>k;
	rep(i,k){
		int a,b;
		cin>>a>>b;
		sche[a] = b;
	}
	if(sche[n]>0 && sche[n-1]>0){
		dp[n-1][sche[n-1]][sche[n]] = 1;
	}else if(sche[n]>0 && sche[n-1]==0){
		dp[n-1][1][sche[n]] = 1;
		dp[n-1][2][sche[n]] = 1;
		dp[n-1][3][sche[n]] = 1;
	}else if(sche[n]==0 && sche[n-1]>0){
		dp[n-1][sche[n-1]][1] = 1;
		dp[n-1][sche[n-1]][2] = 1;
		dp[n-1][sche[n-1]][3] = 1;
	}else{
		REP(i,3){
			REP(j,3){
				dp[n-1][i][j] = 1;
			}
		}
	}

	for(int i = n; i>=1; --i){
		REP(j,3){
			if(sche[i-1]>0 && j != sche[i-1])continue;
			REP(k,3){
				if(sche[i]>0 && k != sche[i])continue;
				REP(l,3){
					if(j == k && l == k)continue;
					dp[i-1][j][k] += dp[i][k][l];
					dp[i-1][j][k] %= 10000;
				}
			}
		}
	}
	
	int ans = 0;
	REP(i,3)REP(j,3)ans += dp[1][i][j];
	cout<<ans%10000<<endl;
	return 0;
}
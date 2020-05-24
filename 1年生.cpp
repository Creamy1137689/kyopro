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

int main(){
	int n;
	cin>>n;
	vector<int> num(n);
	rep(i,n)cin>>num[i];
	vector<vector<ll>> dp(n, vector<ll> (21, 0));
	dp[0][num[0]] = 1;
	for(int i = 1; i<n-1; ++i){
		int dif = num[i];
		rep(j,21){
			if(j+dif<=20)dp[i][j] += dp[i-1][j+dif];
			if(j-dif>=0)dp[i][j] += dp[i-1][j-dif];
		}
	}
	/*
	cout<<"---------------"<<endl;
	rep(i,n-1){
		rep(j,21){
			cout<<dp[i][j];
		}
		cout<<endl;
	}*/
	cout<<dp[n-2][num[n-1]]<<endl;
	return 0;
}
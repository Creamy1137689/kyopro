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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int main(){
	string s;cin>>s;
	vector<vector<int>> dp(s.size()+1,vector<int>(3,0));
	dp[0][1] = 0; dp[0][2] = 0; dp[1][1] = 1; dp[1][2] = 0;
	for(int i = 2; i <= s.size(); ++i){
		chmax(dp[i][1], dp[i-1][2]+1);
		chmax(dp[i][2], dp[i-2][1]+1);
		if(s[i-1] != s[i-2]) chmax(dp[i][1], dp[i-1][1]+1);
		if(i<=3){chmax(dp[i][2], dp[i-2][2]+1); continue;}
		if((s[i-1] != s[i-3] && s[i-2] != s[i-4]))chmax(dp[i][2], dp[i-2][2]+1);
	}
	cout<<max(dp[s.size()][1],dp[s.size()][2])<<endl;
	return 0;
}
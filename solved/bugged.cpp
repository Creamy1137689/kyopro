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

//DPでぶん殴ってオーバーキル
int main(){
	int N;
	cin>>N;
	vector<int> score(N);
	int sum = 0;
	rep(i,N){
		cin>>score[i];
		sum += score[i];
	}
	vector<vector<bool>> dp(N+1,vector<bool>(sum+1,false));
	REP(i,N){
		rep(j,sum+1){
			if(dp[i-1][j])dp[i][j] = true;
			if(j < score[i-1])continue;
			if(j == score[i-1])dp[i][j] = true;
			if(dp[i-1][j-score[i-1]])dp[i][j] = true;
		}
	}
	for(int i = sum; i>=0; --i){
		if(dp[N][i]){
			if(i%10!=0){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}

/*順当に考えたらこんな感じ
int main(){
	int N;
	cin>>N;
	vector<int> score(N);
	int ans = 0;
	int rest = inf;
	rep(i,N){
		cin>>score[i];
		ans += score[i];
		if(score[i]%10 != 0)rest = min(rest,score[i]);
	}
	if(ans % 10 != 0){cout<<ans<<endl; return 0;}
	if(rest != inf){cout<<ans-rest<<endl; return 0;}
	cout<<0<<endl;
	return 0;
}
*/
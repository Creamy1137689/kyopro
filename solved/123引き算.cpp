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

#define rep(i,n) for(int i = 0; i<(n); ++i)
#define REP(i,n) for(int i = 1; i<=(n); ++i)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int N,a,b,c;
	cin>>N>>a>>b>>c;
	bool ans = true;
	vector<int> dp(330,100000);
	if(N == a || N == b || N == c)ans = false;
	dp[N] = 0;
	for(int i = N; i>=0; --i){
		if(i == a || i == b || i == c)continue;
		chmin(dp[i], dp[i+1]+1);
		chmin(dp[i], dp[i+2]+1);
		chmin(dp[i], dp[i+3]+1);
	}
	 // rep(i,N+1)cout<<dp[i]<<endl;
	if(dp[0]>100)ans = false;
	cout<<((ans)?"YES":"NO")<<endl;
	return 0;
}
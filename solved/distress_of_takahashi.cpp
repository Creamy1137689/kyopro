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

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}
int dp[55][55][10100] = {0};

int main(){
	int W, N, K;
	cin >> W >> N >> K;
	vector<P> shot(N);
	rep(i,N)cin >> shot[i].first >> shot[i].second;
	//順にpasted_count, used_num, width
	REP(i,K)REP(j,N)REP(k,W){
		chmax(dp[i][j][k], dp[i][j-1][k]);
		chmax(dp[i][j][k], dp[i-1][j][k]);
		if(k-shot[j-1].first >= 0){
			chmax(dp[i][j][k], dp[i-1][j-1][k-shot[j-1].first] + shot[j-1].second);
		}		
	}
	cout << dp[K][N][W] << endl;
	return 0;
}

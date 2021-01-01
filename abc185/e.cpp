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

int solve(vector<int> a, vector<int> b){
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, inf));
    rep(i,a.size()+1)dp[i][0] = i;
    rep(j,b.size()+1)dp[0][j] = j;
	REP(i,a.size()){
		REP(j,b.size()){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			chmin(dp[i][j], dp[i-1][j]+1);
	        chmin(dp[i][j], dp[i][j-1]+1);
            chmin(dp[i][j], dp[i-1][j-1]+1);
		}
	}
	return dp[a.size()][b.size()];
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    rep(i,N)cin >> a[i];
    rep(i,M)cin >> b[i];
    cout << solve(a, b) << endl;
    return 0;
}

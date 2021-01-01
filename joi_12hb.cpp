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

int lcs_len(vector<int> a, vector<int> b){
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
	REP(i,a.size()){
		REP(j,b.size()){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				chmax(dp[i][j], dp[i][j-1]);
			}
		}
	}
    int res = 0;
    REP(i,a.size())REP(j,b.size())chmax(res, dp[i][j]);
	return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<int> aa(a), ba(b);
    rep(i,a)cin >> aa[i];
    rep(i,b)cin >> ba[i];
    cout << lcs_len(ba, aa) << endl;
    return 0;
}

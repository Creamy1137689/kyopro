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

int lcs_len(string &a, string &b){
    vector<vector<int>> dp(3, vector<int>(4002,0));
    int res = 0;
	REP(i,a.size()){
		REP(j,b.size()){
			if(a[i-1] == b[j-1]){
				dp[1][j] = dp[0][j-1]+1;
			}else{
                dp[1][j] = 0;
            }
		}
        REP(j,b.size())chmax(res, dp[1][j]);
        REP(j,b.size())dp[0][j] = dp[1][j];
	}
	return res;
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << lcs_len(s,t) << endl;
    return 0;
}

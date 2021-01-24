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

int main(){
	string s, t;
	cin >> s >> t;
	int N = t.size();
	stringstream ss;
	ss << setw(N) << setfill('0') << s;
	s = ss.str();
	string dp[N+1][10][3];
	rep(i,N+1)rep(j,200)rep(k,3)dp[i][j][k] = "";
	rep(i,N)rep(j,200)rep(k,3){
		int td = t[i];
		int sd = s[i];
		if(dp[i][j][k] == "")continue;
		rep(d,10){
			int ni = i + 1, nj = j + d, nk = k;
			if(k == 1){
				if(td > d)nk = 0;
				if(td < d)continue;
			}
			if(k == 2){
				if(sd < d)nk = 0;
				if(sd > d)continue;
			}
		}
	}
	return 0;
}

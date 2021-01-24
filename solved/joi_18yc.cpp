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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int H,W; cin>>H>>W;
	vector<vector<int>> nap(H,vector<int> (W));
	rep(i,H)rep(j,W)cin>>nap[i][j];
	int ans = inf;
	rep(i,H)rep(j,W){
		int e_ans = 0;
		rep(y,H)rep(x,W){
			e_ans += min(abs(y-i),abs(x-j))*nap[y][x];
		}
		ans = min(ans , e_ans);
	}
	cout<<ans<<endl;
	return 0;
}
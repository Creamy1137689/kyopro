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

int d8x[8] = {0,1,1,1,0,-1,-1,-1};
int d8y[8] = {1,1,0,-1,-1,-1,0,1};

int main(){
	int H,W;
	cin>>H>>W;
	vector<vector<char>> in(H,vector<char> (W));
	vector<vector<char>> ans(H,vector<char> (W));
	rep(i,H)rep(j,W)cin>>in[i][j];
	rep(i,H)rep(j,W){
		if(in[i][j] == '#'){
			ans[i][j] = '#';
			continue;
		}
		int count = 0;
		rep(k,8){
			int dy = i + d8y[k], dx = j + d8x[k];
			if(dy < 0 || dx < 0 || dy >= H || dx >= W)continue;
			if(in[dy][dx] == '#') ++count;
		}
		ans[i][j] = '0'+ count;
	}
	rep(i,H){rep(j,W)cout<<ans[i][j]; cout<<endl;}
	return 0;
}
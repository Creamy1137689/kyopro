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

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int H, W;
vector<vector<ll>> input(1010, vector<ll>(1010, -1));
vector<vector<ll>> ans(1010, vector<ll>(1010, -1));

ll search(int i, int j){
	if(ans[i][j] != -1){
		return ans[i][j];
	}else{
		ll res = 1;
		ans[i][j] = res;
		rep(k,4){
			int dy = i + d4y[k], dx = j + d4x[k];
			if(input[i][j] < input[dy][dx]){
				res += search(dy, dx);
				res %= MOD;
			}
		}
		ans[i][j] = res;
		return res;
	}
}

int main(){
	cin >> H >> W;
	REP(i,H)REP(j,W){
		cin >> input[i][j];
	}
	ll res = 0;
	REP(i,H)REP(j,W){
		if(ans[i][j] == -1){
			search(i, j);
		}
		res += ans[i][j];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}

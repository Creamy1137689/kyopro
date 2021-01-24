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

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int main(){
	int H,W;
	cin>>H>>W;
	char nap[H+2][W+2];
	REP(i,H)REP(j,W)cin>>nap[i][j];
	int ans = 0;
	REP(i,H)REP(j,W){
		if(nap[i][j] == '#')continue;
		vector<vector<int>> e_ans(H+2,vector<int>(W+2,inf));
		queue<ip> Q;
		Q.push(make_pair(i, j));
		e_ans[i][j] = 0;
		while(!Q.empty()){
			int y = Q.front().first, x = Q.front().second;
			Q.pop();
			rep(k,4){
				int dy = y + d4y[k], dx = x + d4x[k];
				if(nap[dy][dx] == '.' && e_ans[dy][dx] == inf){
					e_ans[dy][dx] = e_ans[y][x] + 1;
					Q.push(make_pair(dy, dx));
				}
			}
		}
		int t_ans = 0;
		REP(k,H)REP(l,W){
			if(e_ans[k][l] == inf)continue;
			t_ans = max(t_ans, e_ans[k][l]);
		}
		ans = max(ans, t_ans);
	}
	cout<<ans<<endl;
	return 0;
}
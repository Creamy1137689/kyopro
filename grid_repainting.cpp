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
	char maze[55][55];
	int ans[55][55];
	int b_cnt = 0;
	REP(i,H)REP(j,W){
		cin>>maze[i][j];
		if(maze[i][j] == '#')++b_cnt;
		ans[i][j] = -1;
	}
	queue<ip> Q;
	Q.push(make_pair(1, 1));
	ans[1][1] = 0;
	while(!Q.empty()){
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		rep(i,4){
			int dy = y+d4y[i], dx = x+d4x[i];
			if(1<=dy && dy<=H && 1<=dx && dx<=W && maze[dy][dx] == '.' && ans[dy][dx] == -1){
				ans[dy][dx] = ans[y][x] + 1;
				Q.push(make_pair(dy, dx));
			}
		}
	}
	int res = ans[H][W];
	if(res==-1){
		cout<<res<<endl;
		return 0;
	}
	cout<<H*W-res-1-b_cnt<<endl;
	return 0;
}
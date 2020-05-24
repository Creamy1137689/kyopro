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
	char nap[55][55];
	int ans[55][55];
	int H,W;
	cin>>H>>W;
	int cnt_blk = 0;
	REP(i,H)REP(j,W){
		cin>>nap[i][j];
		ans[i][j] = inf;
		if(nap[i][j] == '#')cnt_blk++;
	}
	queue<ip> Q;
	ans[1][1] = 0;
	Q.push(make_pair(1, 1));
	while(!Q.empty()){
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		rep(i,4){
			int dy = y + d4y[i], dx = x + d4x[i];
			if(nap[dy][dx] == '.' && ans[dy][dx] == inf){
				ans[dy][dx] = ans[y][x] + 1;
				Q.push(make_pair(dy, dx));
			}
		}
	}
	if(ans[H][W]== inf)cout<<-1<<endl;
	else cout<<H*W-1-cnt_blk-ans[H][W]<<endl;
	return 0;
}
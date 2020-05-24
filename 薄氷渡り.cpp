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

int m[95][95];
int w,h;
int max_depth = 0;

void dfs(int i, int j, int maze[95][95], int e_ans = 0){
	e_ans++;
	maze[i][j] = 0;
	bool sur = true;
	rep(p,4){
		int dy = i + d4y[p], dx = j + d4x[p];
		if(maze[dy][dx] == 1){
			int test[95][95];
			REP(x,h)REP(y,w)test[x][y] = maze[x][y];
			dfs(dy,dx,test,e_ans);
			sur = false;
		}
	}
	if(sur)max_depth = max(max_depth, e_ans);
	return ;
}

int main(){
	cin>>w>>h;
	REP(i,h)REP(j,w)cin>>m[i][j];
	REP(i,h)REP(j,w){
		if(m[i][j]==1){
			int test[95][95];
			REP(p,h)REP(q,w)test[p][q] = m[p][q];
			dfs(i,j,test);
		}
	}
	cout<<max_depth<<endl;
	return 0;
}

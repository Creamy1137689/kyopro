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
	int h,w;
	cin>>h>>w;
	ip s,g;
	cin>>s.first>>s.second>>g.first>>g.second;
	char maze[55][55];
	int ans[55][55];
	REP(i,h)REP(j,w){
		cin>>maze[i][j];
		ans[i][j] = inf;
	}
	queue<ip> Q;
	Q.push(s);
	ans[s.first][s.second] = 0;
	while(!Q.empty()){
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		rep(i,4){
			int dy = y + d4y[i], dx = x + d4x[i];
			if(maze[dy][dx] == '.' && ans[dy][dx] == inf){
				ans[dy][dx] = ans[y][x] + 1;
				Q.push(make_pair(dy, dx));
			}
		}
	}
	cout<<ans[g.first][g.second]<<endl;
	return 0;
}

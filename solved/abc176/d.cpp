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

priority_queue<pair<int, P>, vector<pair<int,P>>, greater<pair<int,P>>> pq;

int H, W, Ch, Cw, Dh, Dw;
vector<vector<char>> nap(1010, vector<char>(1010));
vector<vector<int>> dist(1010, vector<int>(1010, inf));

void dfs(int y, int x){
	rep(i,4){
		int dy = y + d4y[i], dx = x + d4x[i];
		if(nap[dy][dx] == '.' && dist[dy][dx] == inf){
			dist[dy][dx] = dist[y][x];
			dfs(dy, dx);
		}
	}
	for(int i = -2; i < 3; ++i){
		for(int j = -2; j < 3; ++j){
			int dy = y + i, dx = x + j;
			if(nap[dy][dx] == '.' && dist[dy][dx] == inf){
				pq.emplace(dist[y][x], make_pair(dy, dx));
			}
		}
	}
}

int main(){
	cin >> H >> W;
	cin >> Ch >> Cw >> Dh >> Dw;
	++Ch; ++Cw; ++Dh; ++Dw;
	for(int i = 2; i <= H + 1; ++i)for(int j = 2; j <= W+1; ++j)cin >> nap[i][j];

	pq.emplace(-1, make_pair(Ch, Cw));
	while(!pq.empty()){
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int bf_cost = pq.top().first;
		pq.pop();
		if(dist[y][x] == inf){
			dist[y][x] = bf_cost + 1;
			dfs(y,x);
		}
	}
	int ans = dist[Dh][Dw];

	//cout << line << endl;
	//for(int i = 2; i <= H+1; ++i){
	//	for(int j = 2; j <= W+1; ++j){
	//		printf("%2d ", ((dist[i][j] != inf) ? dist[i][j] : -1));
	//	}
	//	cout << endl;
	//}
	//cout << line << endl;

	if(ans == inf)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}

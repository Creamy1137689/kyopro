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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int main(){
	int H, W, D;
	cin>>H>>W>>D;
	vector<vector<int>> nap(1010, vector<int>(1010, 0));
	vector<vector<int>> dist(1010, vector<int>(1010, inf));
	REP(i,H)REP(j,W)cin>>nap[i][j];
	queue<P> Q;
	Q.push(make_pair(1,1));
	dist[1][1] = 0;
	int x,y,dx,dy;
	int ans = -1;
	if(D % 2 == 0)ans = nap[1][1];
	while(!Q.empty()){
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		rep(i,4){
			dy = y + d4y[i];
			dx = x + d4x[i];
			if(nap[dy][dx] != 0 && dist[dy][dx] == inf && dist[y][x] < D){
				dist[dy][dx] = dist[y][x] + 1;
				if((D - dist[dy][dx]) % 2 == 0)ans = max(ans, nap[dy][dx]);
				Q.push(make_pair(dy, dx));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
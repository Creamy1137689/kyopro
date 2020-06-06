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

int d6x[6] = {1,0,-1,1,-1,0};
int d6y[6] = {1,1,1,0,0,-1};

int main(){
	int N,GX,GY;
	cin>>N>>GX>>GY;
	GY += 400; GX += 400;
	vector<vector<char>> nap(810,vector<char>(810,'.'));
	vector<vector<int>> ans(810,vector<int>(810,inf));
	rep(i,N){
		int x,y;
		cin>>x>>y;
		x += 400; y += 400;
		nap[y][x] = '#';
	}
	queue<P> Q;
	Q.push(make_pair(400, 400));
	ans[400][400] = 0;
	while(!Q.empty()){
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		rep(i,6){
			int dy = d6y[i] + y, dx = d6x[i] + x;
			if((dx < 0 || dx > 800) || (dy < 0 || dy > 800))continue;
			if(nap[dy][dx] == '#' || ans[dy][dx] != inf)continue;
			ans[dy][dx] = ans[y][x]+1;
			Q.push(make_pair(dy, dx));
		}
	}
	// cout<<line<<endl;
	// for(int i = 397; i<=403; ++i){
	// 	for(int j = 396; j<=403; ++j){
	// 		if(i == 400 && j == 400)cout<<'S';
	// 		else if(i == GY && j == GX)cout<<'G';
	// 		else cout<<nap[i][j];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<line<<endl;
	int res = ans[GY][GX];
	if(res == inf)res = -1;
	cout<<res<<endl;
	return 0;
}
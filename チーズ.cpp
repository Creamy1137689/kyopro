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
	int H,W,N;
	cin>>H>>W>>N;
	vector<ip> chees(N+1);
	char maze[1010][1010];
	REP(i,H)REP(j,W){
		char in;
		cin>>in;
		maze[i][j] = in;
		if('1'<=in && in<='9'){
			chees[in-'0'].first = i;
			chees[in-'0'].second = j;
		}
		if(in == 'S'){
			chees[0].first = i;
			chees[0].second = j;
		}
	}
	queue<ip> Q;
	int ans[1010][1010];
	ans[chees[0].first][chees[0].second] = 0;
	rep(c,N){
		Q.push(chees[c]);
		REP(i,H)REP(j,W){
			if(i == chees[c].first && j == chees[c].second)continue;
			ans[i][j] = inf;
		}
		while(!Q.empty()){
			int y = Q.front().first, x = Q.front().second;
			Q.pop();
			rep(i,4){
				int dy = y+d4y[i], dx = x+d4x[i];
				if(1<=dy && dy<=H && 1<=dx && dx<=W && maze[dy][dx]!='X' && ans[dy][dx] == inf){
					ans[dy][dx] = ans[y][x]+1;
					Q.push(make_pair(dy, dx));
				} 
			}
		}
	}
	cout<<ans[chees[N].first][chees[N].second]<<endl;
	return 0;
}
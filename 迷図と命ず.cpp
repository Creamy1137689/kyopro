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
	while(true){
		int maze[70][70] = {0};
		int ans[70][70] = {0};
		int H,W;
		cin>>W>>H;
		if(H==0 && W==0)break;
		REP(i,2*H-1){
			REP(j,2*W-1){
				ans[i][j] = inf;
			}
		}
		REP(i,2*H-1){
			if(i%2==1){
				REP(j,W-1){
					int in;
					cin>>in;
					if(in == 1){
						maze[i][j*2] = 1;
						maze[i+1][j*2] = 1;
						maze[i-1][j*2] = 1;
					}
				}
			}else{
				REP(j,W){
					int in;
					cin>>in;
					if(in==1){
						maze[i][2*j-1] = 1;
						maze[i][2*j] = 1;
						maze[i][2*(j-1)] = 1;
					}
				}
			}
		}
		queue<ip> Q;
		Q.push(make_pair(1, 1));
		ans[1][1] = 1;
		while(!Q.empty()){
			int y = Q.front().first, x = Q.front().second;
			Q.pop();
			rep(i,4){
				int dy = y + d4y[i], dx = x + d4x[i];
				if(1<=dy && dy<=2*H-1 && 1<=dx && dx<=2*W-1 && ans[dy][dx] == inf && maze[dy][dx] == 0){
					if(dy*dx%2 == 0){
						ans[dy][dx] = ans[y][x];
					}else{
						ans[dy][dx] = ans[y][x] + 1;
					}
					Q.push(make_pair(dy, dx));
				}
			}
		}

		int res = ans[2*H-1][2*W-1];
		if(res==inf)cout<<0<<endl;
		else cout<<res<<endl;
	}
	
	return 0;
}
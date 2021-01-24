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
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int d4x[4] = {0, 1, 0, -1};
int d4y[4] = {1, 0, -1, 0};

int H, W;
char nap[410][410];
int divided[410][410];

void dfs(int i, int j){
	rep(k,4){
		int dy = i + d4y[k];
		int dx = j + d4x[k];
		if(dy < 1 || dx < 1 || dy > H || dx > W)continue;
		if(nap[dy][dx] != nap[i][j]	&& divided[dy][dx] == -1){
			divided[dy][dx] = divided[i][j];
			dfs(dy, dx);
		}
	}
}

int main(){
	cin >> H >> W;
	REP(i,H){
		REP(j,W){
			cin >> nap[i][j];
			divided[i][j] = -1;
		}
	}
	int cnt = 0;
	REP(i,H){
		REP(j,W){
			if(divided[i][j] == -1){
				divided[i][j] = cnt;
				dfs(i,j);
				++cnt;
			}
		}
	}
	vector<lp> bwcount(cnt);
	rep(i,cnt){ bwcount[i].first = 0; bwcount[i].second = 0;}
	REP(i,H){
		REP(j,W){
			if(nap[i][j] == '.'){
				++bwcount[divided[i][j]].first;
			}else{
				++bwcount[divided[i][j]].second;
			}
		}
	}
	ll ans = 0;
	rep(i,cnt){
		ans += bwcount[i].first * bwcount[i].second;
	}
	cout << ans << endl;
	return 0;
}

//struct state{
//	int y;
//	int x;
//	vector<vector<bool>> alvis;
//};
//
//int d4x[4] = {0, 1, 0, -1};
//int d4y[4] = {1, 0, -1, 0};
//
//int main(){
//	int H,W;
//	char nap[410][410];
//	cin >> H >> W;
//	REP(i,H){
//		REP(j,W){
//			cin >> nap[i][j];
//		}
//	}
//	int ans = 0;
//	queue<state> Q;
//	REP(i,H){
//		REP(j,W){
//			set<P> cnt;
//			state sp;
//			vector<vector<bool>> crt(410, vector<bool>(410,false));
//			sp.alvis = crt;
//			sp.y = i; sp.x = j;
//			sp.alvis[i][j] = true;
//			Q.push(sp);
//			while(!Q.empty()){
//				state now = Q.front();
//				Q.pop();
//				rep(k,4){
//					int dy = now.y + d4y[k];
//					int dx = now.x + d4x[k];
//					if(now.alvis[dy][dx] == true)continue;
//					if(dx < 1 || dx > W || dy < 1 || dy > H)continue;
//					if(nap[now.y][now.x] != nap[dy][dx]){
//						if(nap[i][j] != nap[dy][dx])cnt.insert(make_pair(dy,dx));
//						vector<vector<bool>> now_vis = now.alvis;
//						now_vis[dy][dx] = true;
//						state to;
//						
//						to.y = dy; to.x = dx; to.alvis = now_vis;
//						Q.push(to);
//					}
//				}
//			}
//			ans += cnt.size();
//			//cout << line << endl;
//			//for(auto x: cnt)printf("[dy,dx]->[%d,%d]\n", x.first, x.second);
//		}
//	}
//	cout << ans/2 <<endl;
//	return 0;
//}

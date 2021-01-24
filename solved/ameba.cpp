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
#define show(obj) {for(auto x:obj)cout<<x;cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int main(){
	int H,W; cin>>H>>W;
	vector<vector<int>> nap(600, vector<int> (600, 0));
	vector<vector<int>> ans(600, vector<int> (600, 0));
	REP(i,H){
		string s; cin>>s;
		REP(j,W)nap[i][j] = s[j-1]-'0';
	}
	REP(i,H){
		REP(j,W){
			if(nap[i][j] != 0){
				int y = i+1, x = j;
				int t = nap[i][j];
				ans[y][x] = nap[i][j];
				rep(k,4){
					nap[y + d4y[k]][x + d4x[k]] -= t;
				}
			}
		}
	}
	REP(i,H){
		REP(j,W)cout<<ans[i][j];
		cout<<"\n";
	}
	return 0;
}

// int main(){
// 	int H,W; cin>>H>>W;
// 	vector<vector<int>> nap(600,vector<int> (600,0));
// 	vector<vector<int>> ans(600,vector<int> (600,0));
// 	REP(i,H){
// 		string s; cin>>s;
// 		REP(j,W)nap[i][j] = (int)(s[j-1]-'0');
// 	}
// 	rep(_,10000){
// 		int tar = inf;
// 		REP(i,H)REP(j,W){
// 			if(nap[i][j] > 0)tar = min(tar, nap[i][j]);
// 		}
// 		if(tar == inf)break;
// 		REP(i,H){
// 			REP(j,W){
// 				bool is_tar = false;
// 				bool is_arround = true;
// 				rep(k,4){
// 					int dy = i + d4y[k];
// 					int dx = j + d4x[k];
// 					if(nap[dy][dx] == tar)is_tar = true;
// 					if(nap[dy][dx] < tar)is_arround = false;
// 				}
// 				if(is_tar && is_arround){
// 					ans[i][j] = tar;
// 					rep(k,4){
// 						nap[i+d4y[k]][j+d4x[k]] -= tar;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	REP(i,H){
// 		REP(j,W)cout<<ans[i][j];
// 		cout<<"\n";
// 	}
// 	return 0;
// }
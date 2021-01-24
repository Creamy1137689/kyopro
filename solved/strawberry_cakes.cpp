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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int d2y[2] = {1, 0};
int d2x[2] = {0, 1};

int main(){
	int H,W,K; cin>>H>>W>>K;
	vector<vector<char>> input(H+4, vector<char> (W+4,'#'));
	vector<vector<int>> ans(H+4, vector<int> (W+4,inf));
	REP(i,H)REP(j,W)cin>>input[i][j];
	int e_ans = 1;
	REP(i,H)REP(j,W){
		if(input[i][j] != '#')continue;
		ans[i][j] = e_ans;
		int width = 1, height = 1, top = i, left = j;
		while(1){
			bool ok = false;
			rep(k,4){
				int sy, sx;
				if(k == 0){
					sy = top; sx = left-1;
				}else if(k == 1){
					sy = top-1; sx = left;
				}else if(k == 2){
					sy = top; sx = left + width;
				}else{
					sy = top + height; sx = left;
				}
				int dy = d2y[k%2], dx = d2x[k%2];
				int loop_cnt = ((k%2 == 1) ? width : height);
				bool can = true;
				rep(m,loop_cnt){
					int ty = sy + dy*m, tx = sx + dx*m;
					if(input[ty][tx] == '#' || ans[ty][tx] != inf)can = false;
				}
				if(can){
					rep(m,loop_cnt){
						int ty = sy + dy*m, tx = sx + dx*m;
						ans[ty][tx] = e_ans;
					}
					ok = true;
					if(k%2 == 1){
						if(k == 1) --top;
						++height;
					}else{
						if(k == 0) --left;
						++width;
					}
					break;
				}
			}
			if(!ok)break;
		}
		++e_ans;
	}
	REP(i,H){REP(j,W)cout<<ans[i][j]<<' '; cout<<endl;}
	return 0;
}
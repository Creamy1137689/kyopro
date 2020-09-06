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

int main(){
	int H, W, t;
	cin >> H >> W;
	vector<vector<int>> black_choco(H, vector<int>(W));
	vector<vector<int>> sum_black(H+1, vector<int>(W+1, 0));
	vector<vector<int>> white_choco(H, vector<int>(W));
	vector<vector<int>> sum_white(H+1, vector<int>(W+1, 0));
	rep(i,H)rep(j,W){
		cin >> t;
		if((i + j) % 2){
			white_choco[i][j] = t;
			black_choco[i][j] = 0;
		}else{
			white_choco[i][j] = 0;
			black_choco[i][j] = t;
		}
	}
	REP(i,H)REP(j,W){
		sum_black[i][j] = sum_black[i-1][j] + sum_black[i][j-1] - sum_black[i-1][j-1] + black_choco[i-1][j-1];
		sum_white[i][j] = sum_white[i-1][j] + sum_white[i][j-1] - sum_white[i-1][j-1] + white_choco[i-1][j-1];
	}
	//rep(i,H+1){rep(j,W+1)printf("%2d ", sum_black[i][j]); cout << "\n";}
	int ans = 0;
	REP(i,H)REP(j,W){
		for(int ly = 0; ly + i <= H; ++ly){
			for(int lx = 0; lx + j <= W; ++lx){
				int ry = ly + i, rx = lx + j;
				int white = sum_white[ry][rx] + sum_white[ly][lx] - sum_white[ry][lx] - sum_white[ly][rx];
				int black = sum_black[ry][rx] + sum_black[ly][lx] - sum_black[ry][lx] - sum_black[ly][rx];
				if(white == black)ans = max(ans, i * j);
				//printf("[y[%d...%d), x[%d...%d)] = [black:%d, white:%d]\n", ly, ry, lx, rx, black, white);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

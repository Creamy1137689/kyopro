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

struct dat{
	int fx;
	int fy;
	int tx;
	int ty;
};

int main(){
	int H,W; cin>>H>>W;
	vector<vector<int>> nap(H, vector<int> (W));
	rep(i,H)rep(j,W)cin>>nap[i][j];
	int ans_count = 0;
	vector<dat> ans;
	rep(i,H-1){
		rep(j,W){
			if(nap[i][j] % 2 == 1){
				--nap[i][j];
				++nap[i+1][j];
				ans.push_back({i, j, i+1, j});
				++ans_count;
			}
		}
	}
	rep(j,W-1){
		if(nap[H-1][j] % 2 == 1){
			--nap[H-1][j];
			++nap[H-1][j+1];
			ans.push_back({H-1, j, H-1, j+1});
			++ans_count;
		}
	}
	cout<<ans_count<<endl;
	rep(i,ans.size()){
		dat e = ans[i];
		printf("%d %d %d %d\n", e.fx+1, e.fy+1, e.tx+1, e.ty+1);
	}
	return 0;
}
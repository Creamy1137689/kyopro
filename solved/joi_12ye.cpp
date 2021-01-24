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
const int MOD = (int)1e9 + 7;

int d6xo[6] = {0,1,1,1,0,-1};
int d6yo[6] = {-1,-1,0,1,1,0};
int d6xe[6] = {-1,0,1,0,-1,-1};
int d6ye[6] = {-1,-1,0,1,1,0};

int main(){
	int H,W;
	cin>>W>>H;
	vector<vector<int>> nap(128, vector<int>(128,0));
	vector<vector<int>> al(128, vector<int>(128,0));
	rep(i,H)rep(j,W)cin>>nap[i+3][j+3];
	int ans = 0;
	queue<ip> Q;
	Q.push(make_pair(0, 0));
	// int t = 0;
	while(!Q.empty()){
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		rep(i,6){
			int dy,dx;
			if(y%2 == 0){
				dy = y + d6ye[i];
				dx = x + d6xe[i];
			}else{
				dy = y + d6yo[i];
				dx = x + d6xo[i];
			}
			// if(t == 0)printf("[dy:dx] = [%d, %d]\n",dy,dx);
			if(dx < 0 || dy < 0 || dx >123 || dy >123)continue;
			if(al[dy][dx]!=0)continue;
			if(nap[dy][dx] == 1)ans++;
			else {
				al[dy][dx] = 1;
				Q.push(make_pair(dy, dx));
			}
		}
		// ++t;
	}
	// rep(i,H+6){rep(j,W+6)cout<<nap[i][j];cout<<endl;}
	// rep(i,128)show(al[i]);
	cout<<ans<<endl;
	return 0;
}
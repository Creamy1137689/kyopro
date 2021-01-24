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

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};

int main(){
	int N,M,D; cin>>N>>M>>D;
	vector<vector<char>> nap(N,vector<char>(M));
	rep(i,N)rep(j,M)cin>>nap[i][j];
	int ans = 0;
	rep(y,N){
		rep(x,M){
			if(nap[y][x] == '#')continue;
			rep(i,4){
				int nx = x, ny = y;
				int dx = d4x[i], dy = d4y[i];
				bool ok = true;
				rep(k,D-1){
					nx += dx; ny += dy;
					if(nx < 0 || ny < 0 || nx >= M || ny >= N){ok = false; break;}
					if(nap[ny][nx] == '#'){ok = false; break;}
				}
				if(ok){ ++ans;}
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}
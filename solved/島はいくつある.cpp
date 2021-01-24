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

int d8x[8] = {0,1,1,1,0,-1,-1,-1};
int d8y[8] = {1,1,0,-1,-1,-1,0,1};

int m[55][55];
int w,h;

void dfs(int i, int j){
	m[i][j] = 0;
	rep(c,8){
		int dy = i+d8y[c], dx = j+d8x[c];
		if(1<=dx && dx<=w && 1<=dy && dy<=h && m[dy][dx] == 1){
			dfs(dy,dx);
		}
	}
	return ;
}

int main(){
	while(true){
		int ans = 0;
		cin>>w>>h;
		if(w == 0 && h == 0)break;
		REP(i,h)REP(j,w)cin>>m[i][j];
		REP(i,h)REP(j,w){
			if(m[i][j] == 1){
				++ans;
				dfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
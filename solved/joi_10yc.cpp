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

int main(){
	int N,m; cin>>N>>m;
	vector<int> ans(N,0);
	vector<vector<bool>> rel(N, vector<bool> (N,false));
	ans[0] = 1;
	rep(i,m){
		int a,b; cin>>a>>b;
		--a; --b;
		rel[a][b] = true;
		rel[b][a] = true;
	}
	rep(i,N){
		if(rel[0][i])ans[i] = 2;
	}
	rep(i,N){
		if(ans[i] != 2)continue;
		rep(j,N){
			if(rel[i][j] && ans[j] == 0) ans[j] = 3;
		}
	}
	int res = 0;
	rep(i,N)if(ans[i]>1) ++res;
	cout<<res<<endl;
	return 0;
}
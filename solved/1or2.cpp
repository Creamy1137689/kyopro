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

vector<vector<int>> G(100100, vector<int>());
vector<bool> visited(100100, false);

void dfs(int st){
	visited[st] = true;
	for(auto t:G[st]){
		if(!visited[t])dfs(t);
	}
}

int main(){
	int N, M, x, y, z;
	cin >> N >> M;
	rep(i,M){
		cin >> x >> y >> z;
		--x; --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = 0;
	rep(i,N){
		if(!visited[i]){
			++ans;
			dfs(i);
		}
	}
	cout << ans << endl;
	return 0;
}

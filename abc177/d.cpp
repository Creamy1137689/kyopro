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

int N, M, a, b;
vector<vector<int>> G(200200, vector<int>());
vector<int> group(200200, inf);

void dfs(int st, int gnum){
	for(auto x:G[st]){
		if(group[x] == inf){
			group[x] = gnum;
			dfs(x, gnum);
		}
	}
}

int main(){
	cin >> N >> M;
	rep(i,M){
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	group.resize(N);
	int num = 0;
	rep(i,N){
		if(group[i] == inf)dfs(i, num++);
	}
	map<int,int> cnt;
	rep(i,N)cnt[group[i]]++;
	int ans = 1;
	for(auto x:cnt)if(x.first != inf)ans = max(ans, x.second);
	cout << ans << endl;
	return 0;
}

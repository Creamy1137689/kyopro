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

vector<vector<int>> G(100010, vector<int>());

void dfs(int f, vector<int> &froms){
	for(auto t:G[f]){
		if(froms[t] == inf){
			froms[t] = f;
			dfs(t, froms);
		}
	}
}

void dfs2(int f, int c, vector<int> &color){
	for(auto t:G[f]){
		if(color[t] == inf){
			color[t] = c;
			dfs2(t, c, color);
		}
	}
}

int main(){
	int N, a, b;
	cin >> N;
	G.resize(N);
	rep(i,N-1){
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> froms(N, inf);
	froms[0] = -1;
	dfs(0, froms);
	vector<int> dir;
	dir.push_back(N-1);
	int k = N-1;
	while(true){
		if(froms[k] == -1)break;
		dir.push_back(froms[k]);
		k = froms[k];
	}
	reverse(all(dir));
	int pos = (dir.size()-1)/2;
	int bst = dir[pos], wst = dir[pos+1];
	vector<int> color(N,inf);
	color[bst] = 0; color[wst] = 1;
 	dfs2(bst, 0, color); dfs2(wst, 1, color);
	int bcnt = 0, wcnt = 0;
	rep(i,N)((color[i] == 0) ? ++bcnt : ++wcnt);
	cout << ((bcnt > wcnt) ? "Fennec" : "Snuke") << endl;
	return 0;
}

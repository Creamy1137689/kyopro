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

int main(){
	int N,M,Q; cin>>N>>M>>Q;
	int com, x, y;
	vector<vector<int>> edge(N,vector<int>());
	vector<int> node(N);
	rep(i,M){
		int u,v; cin>>u>>v;
		--u; --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	rep(i,N)cin>>node[i];
	rep(i,Q){
		cin>>com;
		if(com == 1){
			cin>>x; --x;
			cout<<node[x]<<endl;
			for(auto t: edge[x]){
				node[t] = node[x];
			}
		}else{
			cin>>x>>y;
			--x;
			cout<<node[x]<<endl;
			node[x] = y;
		}
	}
	return 0;
}
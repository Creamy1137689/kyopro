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
#define show(obj) {for(auto x:obj)cout<<x<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N,u,v,w;cin>>N;
	vector<vector<P>> path(N, vector<P>());
	rep(i,N-1){
		cin>>u>>v>>w;
		--u; --v;
		path[u].push_back(make_pair(v, w));
		path[v].push_back(make_pair(u, w));
	} 
	vector<int>node(N, inf);
	queue<int> Q;
	Q.push(0);
	node[0] = 0;
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto x: path[f]){
			int wei = x.second;
			int t = x.first;
			if(node[t] == inf){
				if(wei % 2 == 1){
					node[t] = node[f] +1;
				}else{
					node[t] = node[f];
				}
				node[t] %= 2;
				Q.push(t);
			}
		}
	}
	show(node);
	return 0;
}
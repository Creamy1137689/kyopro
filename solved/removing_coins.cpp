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

vector<vector<int>> G(200100, vector<int>()); 

//UnweightedTree
//argument -> [Vertex_Size, Start_Node]
//return   -> [Furthest_Node, Diameter]
P tree_diameter(int V, int st){
	int t = st;
	int diameter = 0;
	queue<int> Q;
	vector<int> dist(V, inf);
	dist[st] = 0;
	Q.push(st);
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto x:G[f]){
			if(dist[x] == inf){
				dist[x] = dist[f] + 1;
				Q.push(x);
				if(dist[x] > diameter){
					diameter = dist[x];
					t = x;
				}
			}
		}
	}
	return make_pair(t, diameter);
}

int main(){
	int N;
	cin >> N;
	int a,b;
	G.resize(N);
	rep(i,N-1){
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	P x = tree_diameter(N, 0);
	P y = tree_diameter(N, x.first);
	int furthest_dist = y.second + 1;
	cout << ((furthest_dist % 3 == 2)? "Second" : "First") << endl;
	return 0;
}

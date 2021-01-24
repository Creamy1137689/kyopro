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

int N;
char c;
vector<vector<int>> G(220, vector<int>());

void bfs(int st, vector<int> &dist){
	queue<int> Q;
	Q.push(st);
	dist[st] = 0;
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto t:G[f]){
			if(dist[t] == inf){
				dist[t] = dist[f] + 1;
				Q.push(t);
			}
		}
	}
}

int main(){
	cin >> N;
	rep(i,N)rep(j,N){
		cin >> c;
		if(c == '1')G[i].push_back(j);
	}
	int ans = -1;
	rep(st, N){
		vector<int> dist(N, inf);
		bfs(st, dist);
		int e_ans = -1;
		bool can = true;
		rep(f,N){
			for(auto t:G[f]){
				if(abs(dist[f] - dist[t]) != 1)can = false;
				else e_ans = max({e_ans, dist[f], dist[t]});
			}
		}
		if(can)ans = max(ans, e_ans + 1);
	}
	cout << ans << endl;
	return 0;
}

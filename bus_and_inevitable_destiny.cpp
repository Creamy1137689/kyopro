#include <iomanip>
#include <iostream>
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
	int N,M,a,b,t; cin>>N>>M;
	vector<vector<P>> path(N, vector<P> ());
	rep(i,M){
		cin>>a>>b>>t;
		--a; --b;
		path[a].push_back(make_pair(b,t));
		path[b].push_back(make_pair(a,t));
	}
	int ans = inf, f, al_c, to, n_c;
	rep(st, N){
		priority_queue<P, vector<P>, greater<P>> Q;
		vector<int> dist(N,inf);
		Q.push(make_pair(0, st));
		dist[st] = 0;
		while(!Q.empty()){
			f = Q.top().second;
			al_c = Q.top().first;
			Q.pop();
			for(auto x: path[f]){
				to = x.first;
				n_c = x.second;
				if(dist[to] > al_c + n_c){
					dist[to] = al_c + n_c;
					Q.push(make_pair(dist[to], to));
				}
			}
		}

		int e_nax = 0;
		rep(i,N)e_nax = max(e_nax, dist[i]);
		ans = min(ans, e_nax);
	}
	cout<<ans<<endl;
	return 0;
}
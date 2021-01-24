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
	ll N,a,b,c,Q,K,x,y; cin>>N;
	vector< vector<pair<ll,ll>> > path(N,vector<pair<ll,ll>>());
	rep(i,N-1){
		cin>>a>>b>>c;
		--a; --b;
		path[a].push_back(make_pair(b,c));
		path[b].push_back(make_pair(a,c));
	}
	cin>>Q>>K;
	vector<ll> dist(N,INF);
	queue<int> q;
	q.push(--K);
	dist[K] = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto x: path[f]){
			int t = x.first;
			ll wei = x.second;
			if(dist[t] == INF){
				dist[t] = dist[f] + wei;
				q.push(t);
			}
		}
	}
	vector<P> query(Q);
	rep(i,Q){
		cin>>x>>y;
		--x; --y;
		query[i].first = x;
		query[i].second = y;
	}
	rep(i,Q){
		cout<<dist[query[i].first] + dist[query[i].second]<<endl;
	}
	return 0;
}
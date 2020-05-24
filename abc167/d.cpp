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
	ll N,K;
	cin>>N>>K;
	vector<ll> node(N);
	rep(i,N){
		ll t; cin>>t;
		node[i] = t-1LL;
	}
	ll loop_st;
	ll branch;
	ll loop_len;
	vector<ll> check(N,INF);
	ll bf = 0, to;
	check[0] = 0;
	while(1){
		to = node[bf];
		if(check[to] != INF){
			loop_st = to;
			branch = check[to];
			loop_len = check[bf] - check[to]+1LL;
			break;
		}
		check[to] = check[bf] + 1LL;
		bf = to;
	}
	if(K<branch){
		rep(i,N)if(check[i] == K){
			cout<<i+1<<endl; return 0;
		}
	}
	K -= branch;
	K %= loop_len;

	vector<ll> dist(N,INF);
	dist[loop_st] = 0;
	ll ans;
	bf = loop_st;
	while(1){
		if(dist[bf] == K){
			ans = bf;
		}
		to = node[bf];
		if(dist[to] != INF){
			break;
		}
		dist[to] = dist[bf]+1LL;
		bf = to;
	}
	cout<<ans+1LL<<endl;
}

// int main(){
// 	ll N;
// 	ll K;
// 	cin>>N>>K;
// 	vector<ll> node(N);
// 	rep(i,N){
// 		ll t; cin>>t;
// 		node[i] = t-1LL;
// 	}
// 	//OK
// 	vector<ll> dis(N,INF);
// 	dis[0] = 0LL;
// 	ll bf = 0LL;
// 	ll lp_len;
// 	ll sokomade = 0LL;
// 	ll loop_st;
// 	while(true){
// 		ll to = node[bf];
// 		if(dis[to] != INF){
// 			loop_st = to;
// 			sokomade = dis[to];
// 			lp_len = dis[bf] - dis[to] + 1LL;
// 			break;
// 		}
// 		dis[to] = dis[bf]+1LL;
// 		bf = to;
// 	}
// 	K -= sokomade;
// 	K %= lp_len;


// 	vector<ll> dis2(N,INF);
// 	dis2[loop_st] = 0LL;
// 	bf = loop_st;
// 	while(true){
// 		ll to = node[bf];
// 		if(dis2[to] != INF){
// 			break;
// 		}
// 		dis2[to] = dis2[bf] + 1LL;
// 		bf = to;
// 	}
// 	ll ans = 0LL;
// 	rep(i,N){
// 		if(dis2[i] == K){ans = i+1LL;break;}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }
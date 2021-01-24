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
	ll N; cin>>N;
	map<ll,ll> cnt;
	ll ans = 0;
	rep(i,N){
		ll t; cin>>t;
		cnt[t] ++;
		ans += t;
	}
	ll Q; cin>>Q;
	vector<pair<ll, ll>> query(Q);
	rep(i,Q)cin>>query[i].first>>query[i].second;
	rep(i,Q){
		ll kazu = cnt[query[i].first];
		cnt[query[i].first] = 0;
		cnt[query[i].second] += kazu;
		ans += (query[i].second-query[i].first)*kazu;
		cout<<ans<<endl;
	}
	return 0;
}
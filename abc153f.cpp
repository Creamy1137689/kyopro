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

int N,D,A,seg_len;
vector<pair<ll,ll>> enemy;
ll seg[1000000];

void init(int _n){
	seg_len = 1;
	while(seg_len <= _n)seg_len *= 2;
	rep(i,_n){
		seg[i+seg_len] = enemy[i].second;
	}
}

void add(int l, int r, ll x){
	l += seg_len;
	r += seg_len;
	while(l<r){
		if(l%2 == 1){seg[l] += x; ++l;}
		if(r%2 == 1){seg[r-1] += x; --r;}
		l /= 2; r /= 2;
	}
}

ll get(int k){
	k += seg_len;
	ll res = 0;
	while(k>0){
		res += seg[k];
		k /= 2;
	}
	return res;
}

int main(){
	cin>>N>>D>>A;
	enemy.resize(N);
	rep(i,N)cin>>enemy[i].first>>enemy[i].second;
	sort(all(enemy));
	vector<ll> enemy_dist(N); rep(i,N)enemy_dist[i] = enemy[i].first; 
	ll ans = 0;
	init(N);
	rep(i,N){
		ll now = get(i);
		if(now<0)continue;
		ll attack = now/A + (now%A != 0);
		ll dist = enemy[i].first + 2*D;
		int r = upper_bound(enemy_dist.begin(), enemy_dist.end(), dist)-enemy_dist.begin();
		add(i,r, -attack*A);
		ans += attack;
		// cout<<line<<endl;
		// REP(i,seg_len*2-1){printf("[%d]:%lld\n",i,seg[i]);}
		// cout<<line<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
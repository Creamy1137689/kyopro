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

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N; cin>>N;
	int cnt_zero = 0;
	map<pair<ll,ll>, P> e_ans;
	rep(i,N){
		ll x,y; cin>>x>>y;
		if(x == 0 && y == 0){ ++cnt_zero; continue;}
		ll g = gcd(x,y);
		x /= g;
		y /= g;
		if(y<0) x = -x, y = -y;
		if(y == 0 && x < 0) x = -x, y = -y;
		bool ch = false;
		if(x<=0){
			ch = true;
			ll t = x;
			x = y; y = -t;
		}
		if(ch)e_ans[{x,y}].first++;
		else e_ans[{x,y}].second++;
	}
	ll ans = 1;
	for(auto x: e_ans){
		int a = x.second.first;
		int b = x.second.second;
		ll e = 1;
		e += rep_power_modM(2,a);
		e += rep_power_modM(2,b); e %= MOD;
		--e; --e;
		e %= MOD;
		ans *= e;
		ans %= MOD;
	}
	--ans;
	ans += cnt_zero;
	ans %=MOD; 
	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
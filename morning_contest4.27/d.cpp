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
const ll MOD = 1e9 + 7;

int main(){
	ll N, K; cin>>N>>K;
	ll ans = 0;
	for(ll i = K; i<=N+1; ++i){
		ll max = (2*N-i+1)*i/2 % MOD;
		ll min = (i-1)*i/2 % MOD;
		// cout<<max<<' '<<min<<endl;
		ans += (max-min)+1;
		ans %= MOD;
	}
	if(ans<0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
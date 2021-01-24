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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll factrial_mod(ll x){
	ll ans = 1LL;
	for(ll i = 2; i<=x; ++i){
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

int main(){
	ll N,M;
	cin>>N>>M;
	if(abs(N-M)>1LL){cout<<0<<endl; return 0;}
	ll ans = factrial_mod(N);
	ans *= factrial_mod(M);
	ans %= MOD;
	if(N==M)ans *= 2LL;
	ans %= MOD;
	cout<<ans<<endl;
	return 0;
}
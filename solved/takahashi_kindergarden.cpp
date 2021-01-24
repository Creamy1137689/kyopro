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

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll fact(int n){
	ll res = 1;
	REP(i,n){res *= i; res %= MOD;}
	return res;
}

ll rep_power_modM(ll a, ll n, ll M = MOD){
	if(n == 0)return 1;
	if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
	return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N, K;
	cin >> N >> K;
	if(N <= K){
		K %= N;
		COMinit();
		cout << COM(N, K) << endl;
	}else{
		ll ans = fact(N+K-1);
		ll fn = fact(N-1);
		ll fk = fact(K);
		ans *= rep_power_modM(fn, MOD-2); ans %= MOD;
		ans *= rep_power_modM(fk, MOD-2); ans %= MOD;
		cout << ans << endl;	
	}
	return 0;
}

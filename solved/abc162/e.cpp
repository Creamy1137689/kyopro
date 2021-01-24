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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M){
    if(n == 0LL)return 1LL;
    if(n%2 == 0LL){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1LL,M)%M;
}

int main(){
	int N,K;
	cin>>N>>K;
	vector<ll> e_ans(K+1, 0);
	for(int i = K; i>= 1; --i){
		ll t = rep_power_modM(K/i, N, MOD);
		for(int j = 2; i*j<=K; ++j){
			t -= e_ans[i*j];
			if(t < 0) t+=MOD;
		}
		e_ans[i] = t % MOD;
	}
	ll ans = 0LL;
	REP(i,K){
		ans += (e_ans[i]*i)%MOD;
	}
	cout<<ans%MOD<<endl;
}

// int main(){
// 	ll N,K; cin>>N>>K;
// 	int ans = 0;
// 	int cnt = 0;
// 	for(int i = 2; i<=K; ++i){
// 		ll t = rep_power_modM(K/i, N, MOD);
// 		ans += (t*i)%MOD;
// 		cnt += t%MOD;
// 		int div = 0;
// 		for(int j = 1; j*j<=i; ++j){
// 			if(i%j != 0)continue;
// 			if(j*j == i){div ++; ans -= j*t; continue;}
// 			else div += 2;
// 			int oth = i/j;
// 			if(j != 1)ans -= t*j;
// 			if(oth != i)ans -= t+i;
// 		}
// 		div -= 2;
// 		cnt -= div;
// 		ans %= MOD;
// 		cnt %= MOD;
// 	}
// 	printf("[ans]=>%d [cnt]=>%d\n", ans, cnt);
// 	ans += (rep_power_modM(K,N,MOD)-cnt)%MOD;
// 	cout<<ans<<endl;
// 	return 0;
// }
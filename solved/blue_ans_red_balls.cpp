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

ll comb_modM(ll n, ll r, ll M = MOD){
    ll ans = 1; rep(i,r){ans *= (n-i)%M; ans%=M;}
    ll divisor = 1; rep(i,r){divisor *= (i+1)%MOD; divisor %=M;}
    ans = ans * rep_power_modM(divisor,M-2,M)%M; if(ans<0)ans+=M;
    return ans;
}

int main(){
	int N,K; cin>>N>>K;
	REP(i,K){
		ll ans = comb_modM(K-1, i-1);
		if(i-1 > N-K){cout<<0<<endl; continue;}
		ans *= comb_modM(N-K+1, N-K-i+1);
		ans %= MOD;
		if(ans < 0)ans += MOD;
		cout<<ans<<endl;
	}
	return 0;
}
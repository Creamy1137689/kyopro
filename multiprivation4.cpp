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

bool comp_abs(int a, int b){
	return abs(a) > abs(b);
}

int main(){
	ll N, K, nax = -inf;
	cin>>N>>K;
	vector<ll> A(N);
	ll ans = 1;
	rep(i,N){cin>>A[i]; nax = max(nax, A[i]);}
	sort(all(A), comp_abs);

	if(nax < 0 && K % 2 == 1){
		sort(all(A), greater<ll>());
		rep(i,K){ans *= A[i]; ans %= MOD;}
		if(ans < 0)ans += MOD;
		cout<<ans<<endl;
		return 0;
	}

	ll cnin = -inf, cnax = -inf;
	rep(i,K){
		if(A[i]>=0){
			if(cnax == -inf){
				cnax = A[i];
			}else{
				ans *= cnax;
				ans %= MOD;
				cnax = A[i];
			}
		}else{
			if(cnin == -inf){
				cnin = A[i];
			}else{
				ans *= cnin;
				ans %= MOD;
				cnin = A[i];
			}
		}
	}
	// cout<<cnin<<' '<<cnax<<endl;
	ll t_ans = ans;
	if(cnin != -inf){t_ans *= cnin; t_ans %= MOD;}
	if(cnax != -inf){t_ans *= cnax; t_ans %= MOD;}
	// cout<<t_ans<<endl;

	if(t_ans < 0 && cnin != -inf && N != K){
		if(N == K+1){
			ll t = A[K];
			ans *= t; ans %= MOD;
			if(t < 0){
				ans *= cnin; ans %= MOD;
			}else{
				ans *= cnax; ans %= MOD;
			}
		}else{
			ll nxt_nin = -inf, nxt_nax = -inf;
			for(ll i = K; i<N; ++i){
				if(nxt_nin == -inf && A[i] < 0)nxt_nin = A[i];
				if(nxt_nax == -inf && A[i] >= 0)nxt_nax = A[i];
			}
			if(cnax == -inf && nxt_nax != -inf){
				ans *= nxt_nax; ans %= MOD;
			}else if(nxt_nax == -inf){
				ans *= nxt_nin; ans %= MOD;
				ans *= cnin; ans %= MOD;
			}else if(nxt_nin == -inf){
				ans *= nxt_nax; ans %= MOD;
				ans *= cnax; ans %= MOD;
			}else{
				ans *= (max(nxt_nin*cnin, nxt_nax*cnax)%MOD);
				ans %= MOD;
			}
		}
	}else{
		ans = t_ans;
	}
	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
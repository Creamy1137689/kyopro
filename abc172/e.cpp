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

ll parm(ll N, ll R){
	ll res = 1;
	for(ll i = 0; i < R; ++i){
		res *= (N-i);
		res %= MOD;
	}
	return res;
}

int main(){
	int N, M;
	cin>>N>>M;
	ll ans = parm(M,N);
	vector<ll> comp(N+1);
	comp[1] = 0; comp[2] = 1;
	for(int i = 3; i<=N; ++i){
		comp[i] = (i-1)*((comp[i-1] + comp[i-2])%MOD)%MOD;
	}
	ans *= comp[N];
	ans %= MOD;
	cout<<ans<<endl;

	ll pm = N*M;
	pm %= MOD;
	ll k = 1;
	REP(i,N){k *= i; k %= MOD;}
	cout<<pm<< ' ' <<k<<endl;
	pm -= k - 1LL;
	
	ans *= pm;
	ans %= MOD;

	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
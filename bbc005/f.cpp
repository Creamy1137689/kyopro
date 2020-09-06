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

ll rep_power_modM(ll a, ll n, ll M = MOD){
	if(n == 0)return 1;
	if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
	return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	ll N, P;
	cin >> N >> P;
	ll rN = rep_power_modM(N, N);
	ll rP = rep_power_modM(P, N);
	ll ans = rN * rep_power_modM(rP, MOD-2);
	ans %= MOD;
	cout << ans << endl;
	return 0;
}

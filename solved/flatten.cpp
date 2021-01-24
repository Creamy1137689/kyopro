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
const ll MOD =1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M = MOD){
	if(n == 0)return 1;
	if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
	return a*rep_power_modM(a,n-1,M)%M;
}

ll inv(ll t){
	return rep_power_modM(t, MOD-2);
}

map<ll, ll> prime_factor(ll n){
    map<ll,ll> com;
    for(ll i = 2LL; i*i<=n; ++i){
        while(n%i==0LL){
            com[i]++;
            n /= i;
        }
    }
    if(n != 1LL)com[n]++;
    return com;
}

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	map<ll, ll> lcms;
	rep(i,N){
		cin >> A[i];
		map<ll, ll> k = prime_factor(A[i]);
		for(auto x:k){
			lcms[x.first] = max(lcms[x.first], x.second);
		}
	}
	ll lcm = 1;
	for(auto x:lcms){
		lcm *= rep_power_modM(x.first, x.second);
		lcm %= MOD;
	}
	ll ans = 0;
	rep(i,N){
		ll t = lcm * inv(A[i]) % MOD;
		ans += t;
		ans %= MOD;
	}
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}

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
const ll MOD = 998244353;

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N; cin>>N;
	map<int, int> total;
	ll ans = 1;
	rep(i,N){
		int t; cin>>t;
		if(i == 0){if(t != 0)ans = 0;}
		else {if(t == 0)ans = 0;}
		total[t]++;
	}
	int i = 0;
	ll bf = 1;
	for(auto x:  total){
		if(x.first != i)ans = 0;
		ans *= rep_power_modM(bf, x.second, MOD);
		ans %= MOD;
		bf = x.second;
		++i;
	}
	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
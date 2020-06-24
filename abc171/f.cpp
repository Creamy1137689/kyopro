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

int main(){
	int K; cin>>K;
	string s; cin>>s;
	int cnt = 0;
	rep(i,s.size()-1){
		if(s[i] != s[i+1])cnt++;
	}
	ll ans = 1;
	ans *= 25 * 25;
	ans *= rep_power_modM(26, cnt) %MOD;
	ans %= MOD;
	int cnt2 = cnt;
	rep(i,K-1){
		cnt += 2;
		cnt2 += 3;
		ans += rep_power_modM(26, cnt2)%MOD;
		ans %=MOD;
		ans += rep_power_modM(26, cnt)%MOD;
		ans %=MOD;
		ans *= 625;
		ans %=MOD;
	}
	ans %= MOD;
	cout<<ans<<endl;
	return 0;
}
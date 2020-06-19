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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N,P; cin>>N>>P;
	string s; cin>>s;
	if(10%P == 0){
		ll ans = 0;
		rep(i,N){
			if((s[i]-'0')%P == 0){
				ans += i+1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	vector<int> rest(N);
	REP(i,N){
		ll t = s[N-i]-'0';
		rest[i-1] = (t*rep_power_modM(10,i-1, P)) % P;
	}
	vector<int> sum(N+1,0);
	map<ll,ll> cnt;
	cnt[0]++;
	rep(i,N){
		sum[i+1] = (sum[i]+rest[i]) % P;
		cnt[sum[i+1]]++;
	}
	ll ans = 0LL;
	for(auto x:cnt){
		ans += x.second*(x.second-1LL)/2;
	}
	cout<<ans<<endl;
	return 0;
}
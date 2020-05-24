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

ll n_based(ll t){
	ll base = t;
	ll ans = 0;
	ll cnt = 0;
	while(t!=0){
		ans += t%10 * pow(base,cnt);
		t /= 10;
		++cnt;
	}
	return ans;
}

int main(){
	ll a; cin>>a;
	ll k = 10;
	for(; ; ++k){
		ll t = n_based(k);
		if(t==a){cout<<k<<endl;break;}
		if(t>a){
			cout<<-1<<endl; break;
		}
	}
	return 0;
}
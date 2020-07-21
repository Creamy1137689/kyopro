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
#define show(obj) {for(auto x:obj)cout<<x.first<<' '<<x.second<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	ll N,K,a; cin>>N>>K;
	ll ans = 1;
	vector<ll> plus;
	vector<ll> minus;
	rep(i,N){
		cin>>a;
		if(a < 0)minus.push_back(a);
		else plus.push_back(a);
	}
	sort(all(plus),greater<ll>());
	sort(all(minus),greater<ll>());

	//all num is minus ^ K is odd
	if(plus.size() == 0 && K%2 == 1){
		rep(i,K){
			ans *= minus[i];
			ans %= MOD;
		}
		if(ans < 0)ans += MOD;
		cout<<ans<<endl;
		return 0;
	}
	
	//else
	if(K % 2 == 1){
		ans = plus[0]; plus.erase(plus.begin());
		--K;
	}

	vector<pair<int,ll>> exd;
	for(ll i = 0; i<plus.size(); i += 2){
		if(i+1 >= plus.size())exd.push_back(make_pair(1,plus[i]));
		else exd.push_back(make_pair(2,plus[i]*plus[i+1]));
	}
	for(ll i = 0; i<minus.size(); i += 2){
		if(i+1 >= minus.size())exd.push_back(make_pair(1,minus[i]));
		else exd.push_back(make_pair(2,minus[i]*minus[i+1]));
	}
	sort(all(exd), greater<pair<int,ll>>());

	show(exd);
	for(ll i = 0; K > 0 ; ++i){
		ans *= (exd[i].second%MOD);
		ans %= MOD;
		K -= exd[i].first;
	}
	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
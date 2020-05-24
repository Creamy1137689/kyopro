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

int main(){
	int N,M;cin>>N>>M;
	multiset<ll> items;
	rep(i,N){
		ll t; cin>>t;
		items.insert(t);
	}
	// cout<<"inputted"<<endl;
	rep(i,M){
		auto it = items.rbegin();
		ll t = *it; t /= 2;
		items.erase(items.find(*it));
		items.insert(t);
	}
	ll ans = 0;
	for(auto x:items){
		ans += x;
	}
	cout<<ans<<endl;
	return 0;
}

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

int dig_sum(ll k){
	int res = 0;
	while(k > 0){
		res += k%10;
		k /= 10;
	}
	return res;
}

int main(){
	ll N; cin>>N;
	int ans = 0;
	set<ll> anss;
	for(int i = 1; i<170; ++i){
		ll t = N-i;
		if(t < 0)break;
		if(dig_sum(t) == i){
			++ans;
			anss.insert(t);
		}
	}
	cout<<ans<<endl;
	for(auto x: anss)cout<<x<<endl;
	return 0;
}
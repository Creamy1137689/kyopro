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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n;
	cin>>n;
	vector<ll> ball(n);
	map<ll,ll> m;
	rep(i,n){
		cin>>ball[i];
		m[ball[i]]++;
	}
	ll ans = 0LL;
	for(auto x : m){
		ans += x.second * (x.second-1LL)/2;
	}
	rep(i,n){
		ll t = m[ball[i]];
		ll n_ans = ans;
		n_ans -= t * (t-1LL) /2LL;
		n_ans += max((t-1LL)*(t-2LL)/2LL,0LL);
		cout<<n_ans<<endl;
	}
	return 0;
}

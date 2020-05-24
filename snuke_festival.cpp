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
	ll n;
	cin>>n;
	vector<int> a(n), b(n), c(n);
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];
	rep(i,n)cin>>c[i];
	sort(all(a));
	sort(all(c));
	ll ans = 0LL;
	rep(i,n){
		int mid = b[i];
		ll cnt_a, cnt_c;
		auto itr = lower_bound(all(a), mid);
		cnt_a = distance(a.begin(), itr);
		itr = upper_bound(all(c), mid);
		cnt_c = n - distance(c.begin(), itr);
		ans += cnt_a*cnt_c;
	}
	cout<<ans<<endl;
	return 0;
}
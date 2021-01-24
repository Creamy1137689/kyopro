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
	vector<int> a(n), b(n);
	ll ans = 0;
	rep(i,n){
		cin>>a[i]>>b[i];
		ans += abs(b[i]-a[i]);
	}
	int s, t;
	sort(all(a));
	sort(all(b));
	s = ((n%2==1)?a[n/2]: (a[n/2]+a[n/2-1])/2);
	t = ((n%2==1)?b[n/2]: (b[n/2]+b[n/2-1])/2);
	
	rep(i,n){
		ans += abs(s-a[i]) + abs(t-b[i]);
	}
	cout<<ans<<endl;
	return 0;
}

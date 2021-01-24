#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n,m;
	cin>>n>>m;
	vector<lp> d(n);
	rep(i,n)cin>>d[i].first>>d[i].second;
	sort(all(d));
	ll ans = 0;
	rep(i,n){
		if(d[i].second<m){
			ans += d[i].second*d[i].first;
			m -= d[i].second;
			continue;
		}
		ans += m*d[i].first;
		break;
	}
	cout<<ans<<endl;
	return 0;
}
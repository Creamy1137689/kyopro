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
	ll l,r; cin>>l>>r;
	ll mod = 2019LL;
	vint ans;
	if(r-l+1>=2019){cout<<0<<endl; return 0;}
	for(ll i = l; i<=r; ++i){
		ans.push_back(i%mod);
	}
	int res = inf;
	for(int i = 0; i<ans.size(); ++i){
		for(int j=i+1; j<ans.size(); ++j){
			res = min(res, (int)((ans[i]*ans[j])%mod));
		}
	}
	cout<<res<<endl;
	return 0;
}

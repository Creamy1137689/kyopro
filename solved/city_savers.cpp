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
	int n; cin>>n;
	vector<ll> a(n+1);
	rep(i,n+1)cin>>a[i];
	vector<ll> b(n);
	rep(i,n)cin>>b[i];
	ll ans = 0;
	rep(i,n){
		if(a[i]>=b[i]){
			ans += b[i];
			continue;
		}
		ans += a[i];
		ll rest = b[i]-a[i];
		if(a[i+1]>=rest){
			ans+=rest;
			a[i+1] -= rest;
			continue;
		}
		ans += a[i+1];
		a[i+1] = 0;
	}
	cout<<ans<<endl; return 0;
}

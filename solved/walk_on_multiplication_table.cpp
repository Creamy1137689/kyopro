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
#define all(x) begin(perm),end(perm)
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
	ll n;cin>>n;
	ll u_mid = (int)sqrt(n);
	ll l_mid = u_mid;
	ll ans = 0LL;
	while(true){
		if(n%u_mid==0LL){ans = u_mid+n/u_mid; break;}
		if(n%l_mid==0LL){ans = l_mid+n/l_mid; break;}
		++u_mid; --l_mid;
	}
	cout<<ans-2LL<<endl; return 0;
}

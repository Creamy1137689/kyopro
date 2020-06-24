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

int main(){
	ll H,W;
	cin>>H>>W;
	ll ans = INF;
	if(H*W % 3 == 0){
		ans = 0;
	}
	if(H*W % 2 == 0){
		ll a = 100000000, b = 100000000;
		if(H%2 == 0)a = H/2;
		if(W%2 == 0)b = W/2;
		ans = min({a,b,ans});
	}
	if((H-2) %3 == 0 && H >2){
		ans = min(ans, W);
	}
	if((W-2) %3 == 0 && W > 2){
		ans = min(ans, H);
	}
	ll lw = W/2+1;
	ll lh = H/2+1;
	ll sw = W/2;
	ll sh = H/2;
	ll B = lw*sh;
	ll C = sw*lh;
	ans = min(ans, sw*sh-abs(B-C));
	cout<<ans<<endl;
	return 0;
}
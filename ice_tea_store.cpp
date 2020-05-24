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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	long double Q,H,S,D;
	ll N;
	cin>>Q>>H>>S>>D>>N;
	Q *= 4; H *= 2; D /= 2;
	ll ans = 0LL;
	if(min({Q,H,D,S}) == D){
		ans += N/2 * (2*D);
		N  %= 2;
	}
	ans += min({Q,H,S})*N;
	cout<<ans<<endl;
	return 0;
}
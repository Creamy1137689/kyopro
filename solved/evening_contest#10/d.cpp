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
	ll N,K;
	cin>>N>>K;
	ll ans = 0LL;
	REP(i,N){
		ans += (N+1)/i * max(0LL, i-K);
		ans += max((N+1)%i-K, 0LL);
	}
	if(K==0) ans -= N;
	cout<<ans<<endl;
	return 0;
}
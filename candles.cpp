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
	int n,k;
	cin>>n>>k;
	vector<int> candle(n);
	vector<ll> sum(n,0);
	cin>>candle[0];
	REP(i,n-1){
		cin>>candle[i];
		sum[i] = sum[i-1] + (candle[i] - candle[i-1]);
	}
	ll ans = INF;
	for(int l = 0; l+k-1<n; ++l){
		int r = l+k-1;
		ll tmp = sum[r]-sum[l];
		tmp += min(abs(candle[l]), abs(candle[r]));
		ans = min(ans, tmp);
	}
	cout<<ans<<endl;
	return 0;
}

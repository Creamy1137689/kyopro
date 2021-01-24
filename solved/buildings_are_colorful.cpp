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
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	ll ans = INF;
	for(int bit = 0; bit<(1<<n); ++bit){
		vector<bool> look(n,false);
		int cnt = 0;
		rep(i,n){
			if(bit & (1<<i)){
				cnt++;
				look[i] = true;
			}
		}
		if(cnt<k)continue;
		ll e_ans = 0LL;
		ll e_max = 0LL;
		rep(i,n){
			if(look[i]){
				if(e_max < a[i]){e_max = a[i]; continue;}
				e_ans += e_max-a[i]+1LL;
				e_max++;
			}else{
				e_max = max(e_max, a[i]);
			}
		}
		ans = min(ans, e_ans);
	}
	cout<<ans<<endl;
	return 0;
}

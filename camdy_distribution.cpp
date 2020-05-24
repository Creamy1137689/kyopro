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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N,M;cin>>N>>M;
	vector<int> A(N);
	rep(i,N){
		int t; cin>>t;
		A[i] = t%M;
	}
	vector<int> sum(N+1);
	map<int,int> cnt;
	++cnt[0];
	rep(i,N){
		sum[i+1] = (sum[i]+ A[i])%M;
		cnt[sum[i+1]]++;
	}
	ll ans = 0;
	for(auto x: cnt)ans += (ll)x.second*(x.second-1)/2;
	cout<<ans<<endl;
	return 0;
}
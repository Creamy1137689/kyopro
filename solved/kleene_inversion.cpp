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
const ll MOD = 1e9 + 7;

int main(){
	ll N,K; cin>>N>>K;
	vector<int> num(N);
	rep(i,N)cin>>num[i];
	ll lat_big = 0, inn_big = 0;
	rep(i,N){
		for(int j = i+1; j<N; ++j){
			if(num[i]>num[j]) ++lat_big;
		}
		rep(j,N){
			if(num[i]>num[j]) ++inn_big;
		}
	}
	ll ans = 0;
	ans += lat_big*K%MOD;
	ans += ((K-1LL)*K/2%MOD) * inn_big %MOD;
	ans %= MOD;
	if(ans < 0)ans += MOD;
	cout<<ans<<endl;
	return 0;
}
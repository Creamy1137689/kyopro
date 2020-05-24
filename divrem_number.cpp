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
	ll N; cin>>N;
	set<ll> fact;
	for(ll i = 1; i*i<=N; ++i){
		if(N%i == 0){
			fact.insert(i);
			fact.insert(N/i);
		}
	}
	ll ans = 0;
	for(auto x: fact){
		if(x == 1)continue;
		if(N/x == N/(x-1LL)){
			ans += x-1LL;
		}
	}
	cout<<ans<<endl;
	return 0;
}

// int main(){
// 	ll N; cin>>N;
// 	REP(i,N){
// 		printf("[%2d]:[%2lld / %2lld]\n", i, N/i, N%i);
// 	}
// 	return 0;
// }
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
	int N; cin>>N; --N;
	vector<int> K(N);
	rep(i,N)cin>>K[i];
	vector<int> ans(N+1);
	ans[0] = K[0];
	ans[N] = K[N-1];
	for(int i = 1; i<N; ++i){
		ans[i] = min(K[i-1], K[i]);
	}
	rep(i,N+1)cout<<ans[i]<<endl;
	return 0;
}

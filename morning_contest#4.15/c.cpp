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
	int N,X; cin>>N>>X;
	vector<int> t(N+1);
	t[N] = X;
	rep(i,N)cin>>t[i];
	sort(all(t));
	vector<int> dis(N);
	rep(i,N)dis[i] = t[i+1]-t[i];
	int ans = dis[0];
	REP(i,N-1)ans = __gcd(ans, dis[i]);
	cout<<ans<<endl;
	return 0;
}
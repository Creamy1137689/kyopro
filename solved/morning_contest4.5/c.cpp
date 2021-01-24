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
	int N;
	cin>>N;
	vector<int> a(N+1);
	rep(i,N+1)cin>>a[i];
	//if(N==1){cout<<abs(a[1]-a[0])<<endl; return 0;}
	vector<int> dis(N);
	rep(i,N)dis[i] =abs( a[i+1]-a[i]);
	int ans = __gcd(dis[0],dis[1]);
	for(int i = 2; i<N; ++i)ans = __gcd(ans, dis[i]);
		cout<<ans<<endl;
	return 0;
}
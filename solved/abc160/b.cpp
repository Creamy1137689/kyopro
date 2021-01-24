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
	int x;
	cin>>x;
	ll ans = 0, e1 = 0,e2  = 0;
	e1 += x/500;
	ans += e1*1000;
	x %= 500;
	e2 += x/5;
	ans += e2*5;
	x /= 50;
	cout<<ans<<endl;
	return 0;
}
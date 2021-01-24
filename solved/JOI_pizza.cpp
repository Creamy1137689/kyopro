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
	int d, n, m;
	cin>>d>>n>>m;
	vector<int> shop(n+1,0);
	REP(i,n-1)cin>>shop[i];
	shop[n] = d;
	sort(all(shop));
	vector<int> house(m,0);
	rep(i,m)cin>>house[i];
	int ans = 0;
	rep(i,m){
		auto itr = lower_bound(all(shop), house[i]);
		int dis = min((int)(*itr - house[i]), inf);
		dis = min(dis, (int)(house[i] - *(--itr)));
		ans += dis;
	}
	cout<<ans<<endl;
	return 0;
}
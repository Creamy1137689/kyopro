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
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<int> p(a);
	vector<int> q(b);
	vector<int> r(c);
	rep(i,a)cin>>p[i];
	rep(i,b)cin>>q[i];
	rep(i,c)cin>>r[i];
	sort(all(p));
	sort(all(q));
	sort(all(r));
	vector<ip> check;
	rep(i,x)check.push_back(make_pair(p[a-i-1],1));
	rep(i,y)check.push_back(make_pair(q[b-i-1],2));
	rep(i,min(x+y, c))check.push_back(make_pair(r[c-i-1],3));
	sort(all(check));
	//for(auto x:check)cout<<x.first<<' '<<x.second<<endl;
	ll ans = 0LL;
	ll cnt = 0LL;
	ll now = check.size();
	while(x+y-cnt>0){
		now--;
		if(check[now].second == 1){if(x==0)continue; --x;}
		if(check[now].second == 2){if(y==0)continue; --y;}
		if(check[now].second == 3)++cnt;
		//cout<<check[now].first<<' '<<check[now].second<<endl;
		ans += check[now].first;
		//cout<<"   "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
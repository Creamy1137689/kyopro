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
	ll x,y; cin>>x>>y;
	ll x_ = -x, y_ = -y;
	ll ans = INF;
	ll t;
	t = y-x; if(t<0)t = INF;
	ans = min(ans, t);
	t = y_ - x_ + 2; if(t<0)t = INF;
	ans = min(ans, t);
	t = y - x_ + 1; if(t<0)t = INF;
	ans = min(ans, t);
	t = y_ - x + 1; if(t<0)t = INF;
	ans = min(ans, t);
	cout<<ans<<endl;
}

// int main(){
// 	ll x,y; cin>>x>>y;
// 	if(abs(x)<abs(y)){
// 		if(x<0 && y<0){
// 			cout<<abs(y)-abs(x)+2<<endl;
// 		}else{
// 			cout<<abs(y)-abs(x) + (x<0 || y<0)<<endl;
// 		}
// 	}else if(abs(y) > abs(x)){
// 		if(x>=0 && y>=0){cout<<abs(x)+abs(y)+1<<endl;}
// 		else if(x>=0 && y<0){cout<<x+y+1<<endl;}
// 		else if(x<0 && y>=0){cout<<abs(x)+abs(y)<<endl;}
// 		else if(x<0 && y<0){cout<<abs(x)-abs(y)<<endl;}
// 	}else{
// 		if((x>=0 && y>=0) || (x<0 && y<0))cout<<0<<endl;
// 		else cout<<1<<endl;
// 	}
// 	return 0;
// }
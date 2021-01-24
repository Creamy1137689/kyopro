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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int a,b,c;cin>>a>>b>>c;
	if(a==b && b==c && !(a%2)){cout<<-1<<endl; return 0;}
	bool ok = true;
	int ans = 0;
	if(a%2 || b%2 || c%2)ok = false;
	a /= 2; b /= 2; c /= 2;
	while(ok){
		int x = a+b, y = b+c, z = c+a;
		a = x; b = y; c = z;
		++ans;
		if(a%2 || b%2 || c%2)ok = false;
		a /= 2; b /= 2; c /= 2;
	}
	cout<<ans<<endl;
	return 0;
}
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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	ll l, r;
	cin >> l >> r;
	if(abs(r-l) >= 2019){
		cout << 0 << endl;
		return 0;
	}
	l %= 2019;
	r %= 2019;
	if(l >= r)r += 2019;
	ll ans = INF;
	for(int i = l; i <= r; ++i){
		for(int j = i + 1; j <= r; ++j){
			ans = min(ans, (i*j)%2019LL);
		}
	}
	cout << ans << endl;
	return 0;
}

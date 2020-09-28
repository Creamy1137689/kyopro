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
	vector<P> ans(100);
	vector<int> height(1500, 0);
	int x = 0;
	int y = 0;
	int next_add = 100;
	for(int i = 99; i >= 0; --i){
		int nx = x + (i + 1)*2;
		if(nx > 1499){
			x = 0;
			y += next_add * 2 + 1;
			next_add = i + 1;
			nx = x + (i + 1)*2;
		}
		ans[i] = make_pair(x + (i + 1), y + (i + 1));
		x = nx;
	}
	rep(i,100)cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}

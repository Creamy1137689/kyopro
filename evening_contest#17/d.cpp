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
	int sx, sy, tx, ty;
	cin>>sx>>sy>>tx>>ty;
	queue<char> ans;
	rep(i,tx-sx)ans.push('R');
	rep(i,ty-sy)ans.push('U');
	rep(i,tx-sx)ans.push('L');
	rep(i,ty-sy)ans.push('D');
	ans.push('D');
	rep(i,tx-sx+1)ans.push('R');
	rep(i,ty-sy+1)ans.push('U');
	ans.push('L');
	ans.push('U');
	rep(i,tx-sx+1)ans.push('L');
	rep(i,ty-sy+1)ans.push('D');
	ans.push('R');
	while(!ans.empty()){
		cout<<ans.front();
		ans.pop();
	}
	cout<<endl;
	return 0;
}

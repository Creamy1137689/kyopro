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

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
	int h,w;
	cin>>h>>w;
	vector<vector<char>> m(h,vector<char>(w));
	vector<vector<int>> ans(h,vector<int>(w,inf));
	ans[0][0] = 0;
	rep(i,h)rep(j,w)cin>>m[i][j];
	rep(i,h){
		rep(j,w){
			if(j) chmin(ans[i][j], ans[i][j-1] + (m[i][j] != m[i][j-1]));
			if(i) chmin(ans[i][j], ans[i-1][j] + (m[i][j] != m[i-1][j]));
		}
	}
	int res = ans[h-1][w-1];
	if(m[0][0] == '#')++res;
	if(m[h-1][w-1] == '#')++res;
	cout<<res/2<<endl;
}

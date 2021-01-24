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
	long double L,X,Y,S,D; 
	cin>>L>>X>>Y>>S>>D;
	long double ans_l, ans_r;
	long double now = S+L;
	long double to_l = D+2*L;
	long double dist_l = to_l - now; if(dist_l >= L)dist_l -= L;
	long double dist_r = now - D; if(dist_r >= L)dist_r -= L;
	ans_l = (dist_l)/(X+Y);
	ans_r = (dist_r)/(Y-X);
	if(ans_l < 0)ans_l = INF;
	if(ans_r < 0)ans_r = INF;
	cout<<fixed<<setprecision(10)<<min(ans_l, ans_r)<<endl;
	return 0;
}

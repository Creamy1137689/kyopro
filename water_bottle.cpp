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

double a,b,x;
const double pi = 3.141592653589793238;

int main(){
	cin>>a>>b>>x;
	double ans ;
	if(a*a*b/2<x){
		double rest = a*a*b-x;
		double h = rest/a*2/a;
		ans = atan(h/a)*180/pi;
	}else{
		double h = x/a*2/b;
		ans = 90 - atan(h/b)*180/pi;
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}
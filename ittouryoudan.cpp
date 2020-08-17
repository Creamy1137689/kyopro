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
typedef pair<double,double> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

double f(P x, P y, P z){
	return (y.second - x.second)*(z.first - x.first) - (y.first - x.first)*(z.second - x.second);
}

bool ch(P x, P y, P z, P w){
	double t1 = f(x, y, z);
	double t2 = f(x, y, w);
	double t3 = f(z, w, x);
	double t4 = f(z, w, y);

	return (t1*t2 <= 0 && t3*t4 <= 0);
}

int main(){
	int  N, x, y;
	P a,b;
	cin >> a.first >> a.second >> b.first >> b.second >> N;
	vector<P> dots(N+1);
	rep(i,N)cin >> dots[i].first >> dots[i].second;
	dots[N].first = dots[0].first;
	dots[N].second = dots[0].second;
	int ans = 0;
	rep(i,N){
		if(ch(a, b, dots[i], dots[i+1])) {
			++ans;
		}
	}
	cout << ans / 2 + 1 << endl;
	return 0;
}

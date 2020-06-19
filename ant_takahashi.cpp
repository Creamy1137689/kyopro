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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	double x,y;
	int N;
	cin>>x>>y>>N;
	vector<pair<double, double>> vertex(N+1);
	rep(i,N)cin>>vertex[i].first>>vertex[i].second;
	vertex[N] = make_pair(vertex[0].first, vertex[0].second);

	double ans = inf;
	rep(i,N){
		pair<double, double> from = vertex[i];
		pair<double, double> to   = vertex[i+1];
		double a = to.second - from.second;
		double b = to.first - from.first;
		double c = -1*a*from.first + b*from.second;
		// printf("[a,b,c] -> [%f, %f, %f]\n", a,b,c);
		double e_ans = abs(a*x + -1*b*y + c) / sqrt(a*a + b*b);
		// cout<<e_ans<<endl;
		ans = min(ans, e_ans);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}
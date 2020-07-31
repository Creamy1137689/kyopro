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

struct c{
	double bottom;
	double head;
	double r;
	double h;
	double vol;
};

double calc(double vol, double mh, double nh){
	return vol * ((nh*nh*nh)/(mh*mh*mh));
}

int main(){
	int N, Q;
	double a, b;
	cin >> N >> Q;
	vector<c> cone(N);
	rep(i,N){
		cin >> cone[i].bottom >> cone[i].r >> cone[i].h;
		cone[i].head = cone[i].bottom + cone[i].h;
		cone[i].vol = cone[i].r * cone[i].r * 3.141592653589793 * cone[i].h / 3;
		//printf("[%d]->[vol = %f], [bottom:head = %f:%f]\n", i+1, cone[i].vol, cone[i].bottom, cone[i].head);
	}
	rep(_,Q){
		cin >> a >> b;
		long double ans = 0;
		rep(i,N){
			double d_line = min(cone[i].h, max(0.0, cone[i].head-a));
			double u_line = min(cone[i].h, max(0.0, cone[i].head-b));
			//cout << d_line << ' ' << u_line << endl;
			ans += calc(cone[i].vol, cone[i].h, d_line) - calc(cone[i].vol, cone[i].h, u_line);
		}
		cout << fixed << setprecision(10) << ans << endl;
	}
		return 0;
}

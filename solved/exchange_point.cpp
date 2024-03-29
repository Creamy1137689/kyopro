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
	long double N, A, B, t;
	cin >> N >> A >> B;
	long double nin = inf, nax = -1, sum = 0;
	rep(i,N){
		cin >> t;
		nin = min(nin, t);
		nax = max(nax, t);
		sum += t;
	}
	if(nax == nin){
		cout << -1 << endl;
		return 0;
	}
	long double ave = sum/N;
	long double P = B / (nax - nin);
	long double Q = A - P*ave;
	cout << fixed << setprecision(10) << P << ' ' << Q << endl;
	return 0;
}

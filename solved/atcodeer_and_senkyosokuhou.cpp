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
	int N;
	cin >> N;
	vector<LP> ratioa(N);
	rep(i,N)cin >> ratioa[i].first >> ratioa[i].second;
	ll t = 1, a = 1;
	rep(i,N){
		ll need_t = t / ratioa[i].first + (t % ratioa[i].first != 0);
		ll need_a = a / ratioa[i].second + (a % ratioa[i].second != 0);
		t = ratioa[i].first * max(need_t, need_a);
		a = ratioa[i].second * max(need_t, need_a);
		//printf("[%d]->[T = %lld, A = %lld]\n", i+1, t, a);
	}
	cout << t + a << endl;
	return 0;
}

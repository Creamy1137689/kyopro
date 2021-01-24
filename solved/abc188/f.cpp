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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll x, y;

map<ll, ll> costs;
ll A,D;

ll solve(ll N){
	if(N == 0)return abs(x);
        if(N == x)return 0;
	if(costs.count(N) != 0)return costs[N];
	ll res = INF;
	if(N < INF/D)res = abs(N-x)*D;

	//div2
	{
		ll to = N/2*2;
		ll tou = to + 2;
		res = min(res, solve(to/2)+ A + abs(N-to)*D);
		if(tou/2 < N)res = min(res, solve(tou/2) + A + abs(N-tou)*D);
	}

	return costs[N] = res;
}

int main(){
    cin >> x >> y;
    if(x >= y){
        cout << x-y << endl;
        return 0;
    }
    A = 1; D = 1;
    cout << solve(y) << endl;
    return 0;
}

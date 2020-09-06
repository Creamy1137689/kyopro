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
	int K;
	cin >> K;
	vector<ll> order(K);
	vector<LP> ans(K);
	rep(i,K)cin >> order[i];
	ans[K-1] = make_pair(2,2);
	if(order[K-1] != 2){cout << -1 << endl; return 0;}
	for(int i = K-2; i >= 0; --i){
		ans[i].first = (ans[i+1].first + order[i+1])/order[i] * order[i];
		ans[i].second = (ans[i+1].second/order[i] + (ll)(ans[i+1].second % order[i] != 0)) * order[i];
		ll rest_max = ans[i].first / order[i+1] * order[i+1];
		ll rest_min = ans[i].second / order[i+1] * order[i+1];
		if(!(ans[i+1].second <= rest_max && rest_max <= ans[i+1].first))ans[i].first -= order[i];
		if(!(ans[i+1].second <= rest_min && rest_min <= ans[i+1].first))ans[i].second -=order[i];

		// ok or not
		bool ok = true;
		rest_max = ans[i].first / order[i+1] * order[i+1];
		rest_min = ans[i].second / order[i+1] * order[i+1];
		if(!(ans[i+1].second <= rest_max && rest_max <= ans[i+1].first))ok = false;
		if(!(ans[i+1].second <= rest_min && rest_min <= ans[i+1].first))ok = false;
		if(!ok){
			cout << -1 << endl;
			return 0;
		}
		//printf("[%d] -> [max:min = %lld : %lld][order = %lld]\n", i, ans[i].first, ans[i].second, order[i]);
	}
	ll ans_max = ans[0].first + order[0]-1;
	ll ans_min = ans[0].second;
	cout << ans_min << ' ' << ans_max << endl;
	return 0;
}

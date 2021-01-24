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
const ll MOD = 1e9 + 7;

int main(){
	ll N; cin>>N;
	vector<lp> dot(N);
	set<lp> check;
	rep(i,N){
		cin>>dot[i].first>>dot[i].second;
		check.insert(make_pair(dot[i].first, dot[i].second));
	}
	if(N == 1){cout<<1<<endl; return 0;}
	ll ans = inf;
	for(ll i = 0; i<N; ++i){
		for(ll j = 0; j<N; ++j){
			if(i == j)continue;
			ll dx = dot[i].first-dot[j].first;
			ll dy = dot[i].second-dot[j].second;
			vector<bool> dis(N,true);
			rep(k,N){
				if(check.count(make_pair(dx + dot[k].first, dy + dot[k].second))){
					dis[k] = false;
				}
			}
			ll e_ans = 0;
			rep(k,N)if(dis[k]) ++e_ans;
			ans = min(ans, e_ans);
		}
	}
	cout<<ans<<endl;
}

// int main(){
// 	int N; cin>>N;
// 	vector<lp> input(N);
// 	rep(i,N)cin>>input[i].first>>input[i].second;
// 	map<long double, map<pair<long double,long double>,set<int>>> slope;
// 	rep(i,N){
// 		for(int j = i+1; j<N; ++j){
// 			long double sl = (long double)(input[i].second-input[j].second)/(input[i].first-input[j].first);
// 			long double y = input[j].second - input[j].first * sl;
// 			long double x = (sl*input[i].first - input[i].second)/sl;
// 			if(input[i].first == input[j].first )x = input[i].first;
// 			if(input[i].second == input[j].second)y = input[i].second;
// 			slope[sl][make_pair(x,y)].insert(i);
// 			slope[sl][make_pair(x,y)].insert(j);
// 		}
// 	}
// 	int n_cost = 0;
// 	for(auto x: slope){
// 		int cnt = x.second.size();
// 		printf("[same_slope_cnt = %d, slope = %Lf]\n", cnt, x.first);
// 		int uni = 0;
// 		for(auto p:x.second){
// 			printf("     [x, y] = [%Lf, %Lf]\n", p.first.first, p.first.second);
// 			uni += p.second.size();
// 		}
// 		cout<<endl;
// 		n_cost = max(n_cost, uni-cnt);
// 	}
// 	cout<<N-n_cost<<endl;
// 	return 0;
// }
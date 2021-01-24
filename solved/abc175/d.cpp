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
	ll N, K, t;
	cin >> N >> K;
	--K;
	vector<ll> P(N);
	vector<ll> C(N);
	rep(i,N){
		cin >> t;
		P[i] = --t;
	}
	rep(i,N)cin >> C[i];
	ll ans = -INF;
	rep(i,N){
		vector<ll> sum;
		vector<bool> visited(N, false);
		int nt = P[i];
		ll sum_element = 0;
		int cnt = 0;
		while(!visited[nt]){
			visited[nt] = true;
			sum_element += C[nt];
			sum.push_back(sum_element);
			nt = P[nt];
		}

		ll role = K / sum.size();
		ll tail = K % sum.size();
		ll e_ans = -INF;
		for(int j = 0; j <= tail; ++j){
			e_ans = max(e_ans, sum[j]);
		}
		if(sum[sum.size()-1] > 0){
			e_ans += sum[sum.size()-1] * role;
		}

		ll e_ans2 = -INF;
		if(role > 0){
			--role; tail = sum.size()-1;
		}
		for(int j = 0; j <= tail; ++j){
			e_ans2 = max(e_ans2, sum[j]);
		}
		if(sum[sum.size()-1] > 0){
			e_ans2 += sum[sum.size()-1] * role;
		}


		//{
		//	cout << line << endl;
		//	printf("[start = %d] -> [e_ans = %lld]\n", i, e_ans);
		//	printf("[role = %lld], [tail = %lld]\n", role, tail);
		//	show(sum);
		//	cout << line << endl;
		//}
		
		ans = max(ans, e_ans);
		ans = max(ans, e_ans2);
	}
	cout << ans << endl;
	return 0;
}

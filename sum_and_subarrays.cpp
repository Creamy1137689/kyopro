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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	rep(i,N)cin >> A[i];
	vector<ll> sums;
	for(int i = 0; i < N; ++i){
		ll s = 0;
		for(int j = i; j < N; ++j){
			s += A[j];
			sums.push_back(s);
		}
	}
	int len = sums.size();
	vector<bool> can_use(len, true);
	ll ans = 0;
	for(int d = 60; d >= 0; --d){
		int cnt = 0;
		vector<bool> n_can_use = can_use;
		rep(i, len){
			if(can_use[i] && sums[i] & (1ull << d)){
				++cnt;
			}else{
				n_can_use[i] = false;
			}
		}
		if(cnt >= K){
			ans += pow(2,d);
			can_use = n_can_use;
		}
	}
	cout << ans << endl;
	return 0;
}

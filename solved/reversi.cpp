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
	int N, t;
	cin >> N;
	queue<int> Q;
	vector<int> C;
	map<ll, ll> cnt;
	rep(i,N){
		cin >> t;
		Q.push(t);
	}
	C.push_back(Q.front());
	Q.pop();
	while(!Q.empty()){
		if(C[C.size()-1] != Q.front()){
			C.push_back(Q.front());
		}
		Q.pop();
	}
	rep(i,C.size())cnt[C[i]] = 0;
	vector<ll> dp(C.size(), 0);
	dp[0] = 1;
	cnt[C[0]] = 1;
	for(int i = 1; i < C.size(); ++i){
		dp[i] = dp[i-1] + cnt[C[i]];
		dp[i] %= MOD;
		cnt[C[i]] = dp[i];
	}	
	ll ans = dp[C.size()-1];
	ans %= MOD;
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}

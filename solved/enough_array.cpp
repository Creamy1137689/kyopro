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
const int MOD = (int)1e9 + 7;

int main(){
	ll N,K; cin>>N>>K;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	vector<ll> sum(N+1,0);
	rep(i,N)sum[i+1] = sum[i] + A[i];
	// show(sum);
	int left = 0, right = 0;
	ll ans = 0;
	for(; left<=N; ++left){
		for(; right<=N; ++right){
			if(sum[right]-sum[left]>=K){
				ans += N + 1 - right;
				break;
			}
		}
		// printf("[left, right] -> [%d, %d] -> ans = %lld\n",left,right,ans);
	}
	cout<<ans<<endl;
	return 0;
}
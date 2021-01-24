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
	vector<int> A(N+1,1);
	bool ok = false;
	rep(i,N){
		cin>>A[i+1];
		if(A[i+1] == 0)ok = true;
	}
	if(ok){cout<<N<<endl; return 0;}
	ll now = 1;
	int ans = 0;
	int right = 0;
	for(int left = 1; left<=N; ++left){
		now /= A[left-1];
		if(now<=0)now = 1;
		while(now <= K && right<=N){
			right++;
			now *= A[right];
			// printf("[left,right] -> [%d, %d) -> [%lld]\n",left, right, now);
		}
		ans = max(ans, right-left);
	}
	cout<<ans<<endl;
	return 0;
}
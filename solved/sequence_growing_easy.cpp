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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N; cin>>N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];

	//possible or impossible
	if(A[0] != 0){
		cout<<-1<<endl;
		return 0;
	}
	rep(i,N-1){
		if(A[i+1]-A[i] > 1){
			cout<<-1<<endl;
			return 0;
		}
	}

	//way
	ll ans = 0;
	vector<bool> re(N,false);
	REP(i,N-1){
		if(A[i] > A[i-1])++ans;
		else ans += A[i];
	}
	cout<<ans<<endl;
	return 0;
}

// int main(){
// 	int N; cin>>N;
// 	vector<ll> A(N);
// 	rep(i,N)cin>>A[i];
// 	if(A[0] != 0){
// 		cout<<-1<<endl;
// 		return 0;
// 	}
// 	ll ans = A[N-1];
// 	vector<ll> add(N,0);
// 	add[N-1] = A[N-1];
// 	for(int i = N-2; i>=0; --i){
// 		ll need = A[i];
// 		ll max_inh = max(add[i+1]-1, 0LL);
// 		need = max(need - max_inh, 0LL);
// 		// printf("%d -> need = %lld\n", i, need);
// 		add[i] = need;
// 		ans += need;
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }
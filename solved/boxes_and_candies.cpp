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
	ll N, x; cin>>N>>x;
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	ll ans = 0;
	ll l = 0, r = N-1;
	while(r-l > 0){
		if(a[l]+a[l+1] > x){
			ll need = a[l] + a[l+1] - x;
			ll new_next = max(a[l+1]-need, 0LL);
			ans += need;
			a[l+1] = new_next;
		}
		if(r-l == 1)break;
		if(a[r]+a[r-1] > x){
			ll need = a[r]+a[r-1] - x;
			ll new_next = max(a[r-1]-need, 0LL);
			ans += need;
			a[r-1] = new_next;
		}
		++l; --r;
	}
	cout<<ans<<endl;
}

// int main(){
// 	ll N, x; cin>>N>>x;
// 	vector<ll> A(N);
// 	rep(i,N)cin>>A[i];
// 	ll ans = 0;
// 	rep(i,N){
// 		if(i%2 == 1 && i+1 <N){
// 			if(A[i-1]+A[i] > x){
// 				ll mew = max(0LL, x-A[i-1]);
// 				if(mew <= A[i]){
// 					ans += A[i]-mew;
// 					A[i] = mew;
// 				}
// 			}
// 			if(A[i]+A[i+1] > x){
// 				ll mew = max(0LL, x-A[i+1]);
// 				if(mew <= A[i]){
// 					ans += A[i]-mew;
// 					A[i] = mew;
// 				}
// 			}
// 		}
// 	}
// 	rep(i,N-1){
// 		if(A[i]+A[i+1] > x){
// 			ans += A[i] + A[i+1] - x;
// 			if(i%2 == 1){
// 				A[i+1] -= A[i] + A[i+1] - x;
// 			}
// 		}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }
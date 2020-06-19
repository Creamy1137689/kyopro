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
	ll N; cin>>N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	ll ans = 0;
	rep(i,N-1){
		if(A[i] % 2 == 1 && A[i+1]>0){
			++ans;
			--A[i];
			--A[i+1];
		}
	}
	rep(i,N){
		ans += A[i]/2;
	}
	cout<<ans<<endl;
	return 0;
}

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
	vector<int> a(N);
	rep(i,N)cin>>a[i];
	ll ans = 0LL;
	for(int i = 0; i<N; ++i){
		ll e_ans = 1LL;
		while(i+1 < N && a[i] < a[i+1]){
			++e_ans;
			++i;
		}
		ans += e_ans*(e_ans + 1LL)/2;
	}
	cout<<ans<<endl;
	return 0;
}
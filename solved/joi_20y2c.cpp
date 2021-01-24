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

int dig_sum(int a){
	int res = 0;
	while(a > 0){
		res += a%10;
		a /= 10;
	}
	return res;
}

int main(){
	int N; cin >> N;
	vector<int> ans(N+1,0);
	REP(i,N){
		ans[i] ++;
		int to = dig_sum(i) + i;
		if(to > N)continue;
		ans[to] += ans[i];
	}
	cout << ans[N] << endl;
		return 0;
}

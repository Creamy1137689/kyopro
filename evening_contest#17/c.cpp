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

int power(int a, int b){
	return (a-b)*(a-b);
}

int main(){
	int N; cin>>N;
	vector<int> in(N);
	int nin = inf, nax = -112;
	rep(i,N){
		cin>>in[i];
		nax = max(nax, in[i]);
		nin = min(nin, in[i]);
	}
	int ans = inf;
	for(int i = nin; i <= nax; ++i){
		int e_ans = 0;
		rep(j,N){
			e_ans += power(i,in[j]);
		}
		ans = min(ans, e_ans);
	}
	cout<<ans<<endl;
	return 0;
}
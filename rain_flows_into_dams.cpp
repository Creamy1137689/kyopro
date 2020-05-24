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
	int N; cin>>N;
	vector<int> dams(N);
	ll sum = 0, mids = 0;
	rep(i,N){
		cin>>dams[i];
		sum += dams[i];
		if(i % 2 == 0 && i != N-1)mids += dams[i];
	}
	vector<ll> ans(N,-1);
	ans[N-1] = sum-2*mids;
	for(int i = N-1; i>0; --i){
		ans[i-1] = (dams[i-1] - ans[i]/2)*2;
	}
	show(ans);
	return 0;
}
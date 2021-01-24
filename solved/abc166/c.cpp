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
	int N, M;
	cin>>N>>M;
	vector<bool> ans(N,true);
	vector<int> high(N,0);
	rep(i,N)cin>>high[i];
	rep(i,M){
		int a,b; cin>>a>>b;
		--a; --b;
		if(high[a]>high[b])ans[b] = false;
		if(high[a]<high[b])ans[a] = false;
		if(high[a]==high[b]){ans[a] = false; ans[b] = false;}
	}
	int res = 0;
	rep(i,N)if(ans[i])++res;
	cout<<res<<endl;
	return 0;
}
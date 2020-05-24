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
	int N,M;cin>>N>>M;
	vector<bool> ans(N+1, false);
	vector<int> cnt(N+1, 1);
	ans[1] = true;
	rep(i,M){
		int f,t;cin>>f>>t;
		--cnt[f]; ++cnt[t];
		if(!ans[t])ans [t] = ans[f];
		if(cnt[f] == 0){ans[f] = false;}
	}
	int ans_num = 0;
	REP(i,N){
		if(ans[i] && cnt[i]>0) ++ans_num;
	}
	cout<<ans_num<<endl;
	return 0;
}
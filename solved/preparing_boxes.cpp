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
	vector<int> order(N+1);
	rep(i,N)cin>>order[i+1];
	vector<int> ans(N+1,0);
	for(int i = N; i>0; --i){
		int cnt = 0;
		for(int j = 2; i*j<=N; ++j){
			if(ans[i*j] == 1)++cnt;
		}
		if(cnt % 2 != order[i]){
			ans[i] = 1;
		}
	}
	int M = 0;
	REP(i,N){if(ans[i] == 1)M++;}
	cout<<M<<endl;
	if(M>0){
		REP(i,N)if(ans[i] == 1)cout<<i<<endl;
	}
	return 0;
}
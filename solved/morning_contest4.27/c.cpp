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
	vector<int> meet(N);
	rep(i,N)cin>>meet[i];
	if(N==1){cout<<meet[0]<<endl;return 0;}
	int ans = inf;
	int sum = 0;
	rep(i,4)sum += meet[i];
	rep(i,4)ans = min(ans, max(meet[i], sum-meet[i]));
	for(int i = 0; i<N; ++i){
		for(int j = i+1; j<N; ++j){
			int e_ans = meet[i]+meet[j];
			ans = min(ans, max(e_ans, sum-e_ans));
		}
	}
	cout<<ans<<endl;
	return 0;
}
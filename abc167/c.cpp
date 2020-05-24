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
	int N,M,X; cin>>N>>M>>X;
	vector<vector<int>> book(N,vector<int>(M));
	vector<int> cost(N);
	rep(i,N){cin>>cost[i]; rep(j,M)cin>>book[i][j];}
	int ans = inf;
	for(int bit = 0; bit<(1<<N); ++bit){
		int e_ans = 0;
		vector<int> check(M,0);
		for(int i = 0; i<N; ++i){
			if(bit & (1<<i)){
				rep(j,M){
					check[j] += book[i][j];
				}
				e_ans += cost[i];
			}
		}
		bool ok = true;
		rep(i,M)if(check[i]<X)ok = false;
		if(ok) ans = min(ans, e_ans);
	}
	if(ans == inf)ans = -1;
	cout<<ans<<endl;
	return 0;
}
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
	vector<vector<bool>> shop(N,vector<bool>(10));
	vector<vector<int>> earn(N,vector<int>(11));
	rep(i,N){
		rep(j,10){
			int t; cin>>t;
			if(t == 0)shop[i][j] = false;
			else shop[i][j] = true;
		}
	}
	rep(i,N){
		rep(j,11){
			cin>>earn[i][j];
		}
	}

	ll ans = -INF;
	REP(bit, (1<<10)-1){
		vector<bool> open(10);
		rep(i,10){
			if(bit & (1<<i))open[i] = true;
		}
		ll e_ans = 0;
		rep(j,N){
			int cnt = 0;
			rep(k,10){
				if(open[k] && shop[j][k]) ++cnt;
			}
			e_ans += earn[j][cnt];
		}
		ans = max(ans, e_ans);
	}
	cout<<ans<<endl;
	return 0;
}
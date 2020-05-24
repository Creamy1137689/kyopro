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
	vector<vector<char>> from(N,vector<char>(N));
	vector<vector<char>> to(N,vector<char>(N));
	rep(i,N)rep(j,N)cin>>from[i][j];
	rep(i,N)rep(j,N)cin>>to[i][j];
	int ans = inf;
	cout<<endl;
	REP(i,4){
		int e_ans = min(i, 4-i);
		vector<vector<char>> work(N,vector<char>(N));
		rep(j,N)rep(k,N){
			work[N-k-1][j] = from[j][k];
		}
		rep(i,N)rep(j,N){
			if(work[i][j] != to[i][j]) ++e_ans;
		}
		rep(i,N)rep(j,N)from[i][j] = work[i][j];
		ans = min(ans, e_ans); 
	}
	cout<<ans<<endl;
	return 0;
}




// for(int i = 0; i<N; ++i, ++a){
	// 	for(int j = 0; j<N; ++j, ++b){
	// 		if(from[i][j] != to[a][b])++e_ans;
	// 	}
	// }
	// cout<<e_ans<<endl;
	// ans = min(ans, e_ans);
	// a = 0; b = 0; e_ans = 1;
	// for(int i = 0; i<N; ++i, ++a){
	// 	for(int j = N-1; j>=0; --j, ++b){
	// 		if(from[j][i] != to[a][b])++e_ans;
	// 	}
	// }
	// cout<<e_ans<<endl;
	// ans = min(ans, e_ans);
	// a = 0; b = 0; e_ans = 2;
	// for(int i = N-1; i>=0; --i, ++a){
	// 	for(int j = N-1; j>=0; --j, ++b){
	// 		if(from[i][j] != to[a][b])++e_ans;
	// 	}
	// }
	// cout<<e_ans<<endl;
	// ans = min(ans, e_ans);
	// a = 0; b = 0; e_ans = 1;
	// for(int i = N-1; i>=0; --i, ++a){
	// 	for(int j = 0; j<N; ++j, ++b){
	// 		if(from[j][i] != to[a][b])++e_ans;
	// 	}
	// }
	// cout<<e_ans<<endl;
	// ans = min(ans, e_ans);
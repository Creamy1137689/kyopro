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
	int N,M,a,b,t; cin>>N>>M;
	vector<vector<int>> dist(N,vector<int>(N,inf));
	rep(i,N)dist[i][i] = 0;
	rep(i,M){
		cin>>a>>b>>t;
		--a; --b;
		dist[a][b] = min(dist[a][b], t);
		dist[b][a] = min(dist[b][a], t);
	}
	rep(k,N){
		rep(i,N){
			rep(j,N){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = inf;
	rep(f,N){
		int e_ans = 0;
		rep(t,N){
			e_ans = max(e_ans, dist[f][t]);
		}
		ans = min(ans, e_ans);
	}
	cout<<ans<<endl;
	return 0;
}
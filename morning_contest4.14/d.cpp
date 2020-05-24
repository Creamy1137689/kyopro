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
	int N,M; cin>>N>>M;
	vector<vector<bool>> node(110, vector<bool>(110, false));
	rep(i,M){
		int a,b;
		cin>>a>>b;
		node[a][b] = true;
		node[b][a] = true;
	}
	vector<int> vertex(N+1,inf);
	int ans = 0;
	int t_cnt = 0;
	REP(i,N){
		if(vertex[i] != inf)continue;
		queue<ip> Q;
		Q.push(make_pair(i, -1));
		vertex[i] = t_cnt++;
		bool ok = true;
		while(!Q.empty()){
			int nv = Q.front().first;
			int bf = Q.front().second;
			Q.pop();
			REP(j,N){
				if(j == bf)continue;
				if(node[nv][j]){
					if(vertex[j] == inf){
						vertex[j] = vertex[nv];
						Q.push(make_pair(j, nv));
					}else{
						ok = false;
						break;
					}
				}
			}
		}
		if(ok) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}
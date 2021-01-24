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
	int N,C,a; cin>>N>>C;
	// Y,X
	vector<vector<int>> discom(C, vector<int>(C));
	vector<vector<int>> grid(3, vector<int>(C,0));
	rep(i,C)rep(j,C)cin>>discom[i][j];
	REP(i,N)REP(j,N){
		cin>>a;
		--a;
		grid[(i+j)%3][a] ++;
	}
	ll ans = INF;
	rep(f, C){
		rep(s, C){
			rep(t, C){
				if((f-s)*(s-t)*(t-f) == 0)continue;
				ll e_ans = 0;
				rep(k,3){
					int to;
					if(k == 0)to = f;
					if(k == 1)to = s;
					if(k == 2)to = t;
					rep(i,C){
						int el_dis_com = discom[i][to];
						e_ans += grid[k][i] * el_dis_com;
					}
				}
				// printf("[f-s-t] -> [%d-%d-%d] e_ans. %lld\n", f,s,t,e_ans);
				ans = min(ans, e_ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
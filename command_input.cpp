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
	char com[4] = {'A', 'B', 'X', 'Y'};
	int N; cin>>N;
	string st; cin>>st;
	int ans = inf;
	rep(f,4){
		rep(s,4){
			rep(t,4){
				rep(fo,4){
					string com1, com2;
					com1 += com[f]; com1 += com[s];
					com2 += com[t]; com2 += com[fo];
					int e_ans = N;
					rep(i,N-1){
						if((st.substr(i, 2) == com1 || st.substr(i,2) == com2)){--e_ans; ++i;}
					}
					ans = min(ans, e_ans);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
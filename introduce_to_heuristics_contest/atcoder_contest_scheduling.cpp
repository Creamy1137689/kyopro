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
	int D; cin>>D;
	vector<int> cs(26);
	vector<vector<int>> s(D,vector<int> (26));
	vector<int> last(26,-1);
	rep(i,26)cin>>cs[i];
	rep(i,D)rep(j,26)cin>>s[i][j];
	ll sum = 0;

	vector<int> ans(D);
	rep(d, D){
		int m_type;
		ll m_plus = -INF;
		rep(t, 26){
			int e_ans = s[d][t];
			rep(k, 26){
				if(t == k)continue;
				e_ans -= cs[k] * (d - last[k]);
			}
			if(sum + e_ans > m_plus){
				m_plus = sum + e_ans;
				m_type = t;
			}
		}
		sum = m_plus;
		last[m_type] = d;
		ans[d] = m_type + 1;
	}
	// cout<<sum<<endl;
	rep(i,D)cout<<ans[i]<<endl;
	cout<<sum<<endl;
	return 0;
}
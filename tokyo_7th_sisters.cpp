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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	rep(i,N)cin >> A[i];
	vector<P> combo_st(M);
	vector<vector<int>> combo_const(M, vector<int>());
	rep(i,M){
		cin >> combo_st[i].first >> combo_st[i].second;
		rep(j,combo_st[i].second){
			int t;
			cin >> t; --t;
			combo_const[i].push_back(t);
		}
	}
	int ans = 0;
	for(int bit = 0; bit < (1<<N); ++bit){
		set<int> use;
		int e_ans = 0;
		rep(i,N){
			if(bit & (1 << i)){
				e_ans += A[i];
				use.insert(i);
			}
		}
		if(use.size() != 9)continue;
		rep(i,M){
			int cnt = 0;
			for(auto x: combo_const[i]){
				if(use.count(x) != 0)++cnt;
			}
			if(cnt >= 3)e_ans += combo_st[i].first;
		}
		ans = max(ans, e_ans);
	}
	cout << ans << endl;
	return 0;
}

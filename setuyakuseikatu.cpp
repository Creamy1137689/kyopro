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
	string s;
	cin >> s;
	int ans = inf;
	int N = s.size();
	for(int bit = 0; bit < (1 << N); ++bit){
		vector<int> can(41, 0);
		int e_ans = 0;
		rep(i,N){
			if(bit & (1 << i)){
				for(int k = 0; i + k < 40; ++k){
					can[i + k] += (s[k%N] == 'o');
				}
				++e_ans;
			}
		}
		int nax = 0;
		int cur = 0;
		rep(i,41){
			if(can[i] > 0)++cur;
			else{
				nax = max(nax, cur);
				cur = 0;
			}
		}
		if(nax >= N)ans = min(ans, e_ans);
	}
	cout << ans << endl;
	return 0;
}

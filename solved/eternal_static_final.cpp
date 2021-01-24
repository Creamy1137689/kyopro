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
	int N;
	string s;
	cin >> N >> s;
	vector<string> T(N);
	rep(i,N)cin >> T[i];		
	vector<ll> dp(s.size() + 1, 0);
	dp[0] = 1;
	rep(i, s.size()){
		rep(j, N){
			string t = T[j];
			if(i + t.size() - 1 < s.size()){
				string from = s.substr(i, t.size());
				if(t == from){
					dp[i + t.size()] += dp[i];
					dp[i + t.size()] %= MOD; 
				}
			}
		}
	}
	cout << dp[s.size()] << endl;
	return 0;
}

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

set<string> check;
vector<string> ans;

void dfs(string s){
	if(s.size() == 4){
		if(check.count(s) == 0)ans.push_back(s);
	}else{
		rep(i,26){
			dfs(s + (char)('a' + i));
		}
	}
}

int main(){
	int N, K;
	cin >> N >> K;
	vector<string> S(N);
	rep(i,N)cin >> S[i];
	rep(i,N){
		string t;
		if(S[i].size() >= 4)t = S[i].substr(0, 4);
		else t = S[i];
		check.insert(t);
	}
	dfs("");
	rep(i,K){
		cout << ans[i] << endl;
	}
	return 0;
}

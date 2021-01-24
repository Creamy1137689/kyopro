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
	int k; string s; cin>>s>>k;
	set<string> st;
	REP(i,k){
		for(int j = 0; j+i<=s.size(); ++j){
			st.insert(s.substr(j,i));
		}
	}
	for(auto x: st){
		--k;
		if(k == 0){cout<<x<<endl; return 0;}
	}
}

// int k;
// string ans;

// void dfs(string s, string ref){
// 	for(int i = 0; i+s.size()<=ref.size() && s.size() != 0; ++i){
// 		if(s == ref.substr(i, s.size())){
// 			--k;
// 			// cout<<k<<' '<<s<<endl;
// 			if(k == 0)ans = s;
// 			break;
// 		}
// 	}
// 	if(s.size()<5){
// 		rep(i,26){
// 			char c = 'a' + i;
// 			dfs(s+c, ref);
// 		}
// 	}
// }

// int main(){
// 	string s; cin>>s>>k;
// 	set<char> cnt;
// 	rep(i,s.size()){cnt.insert(s[i]);}
// 	if(k == 5 && cnt.size() == 1){
// 		string ans;
// 		rep(i,k)ans += *cnt.begin();
// 		cout<<ans<<endl;
// 		return 0;
// 	}
// 	dfs("", s);
// 	cout<<ans<<endl;
// 	return 0;
// }
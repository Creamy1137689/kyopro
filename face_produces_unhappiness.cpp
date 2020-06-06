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
	int N,K; cin>>N>>K;
	string s; cin>>s;
	vector<pair<char,int>> rang;
	rang.push_back(make_pair(s[0], 1));
	int ans = 0;
	for(int i = 1; i<N; ++i){
		char c = rang[rang.size()-1].first;
		if(s[i] == s[i-1])ans ++;
		if(c != s[i]){
			rang.push_back(make_pair(s[i], 1));
		}else{
			rang[rang.size()-1].second++;
		}
	}
	int nax = rang.size()/2;
	cout<<min(ans + 2*K, N-1)<<endl;
}

// int N, K;
// string s;

// int solve(vector<pair<char,int>> rang, char t, int type){
// 	vector<P> cnt;
// 	rep(i,rang.size()){
// 		if(rang[i].first != t){
// 			cnt.push_back(make_pair(rang[i].second, i));
// 		}
// 	}
// 	if(type)sort(all(cnt)); else sort(all(cnt), greater<P>());
// 	int lp = min((int)cnt.size(), K);
// 	rep(i,lp){
// 		rang[cnt[i].second].first = t;
// 	}
// 	cout<<lp<<' '<<cnt.size()<<endl;

// 	// cout<<line<<endl;
// 	// rep(i,rang.size()){
// 	// 	if(rang[i].first == t)continue;
// 	// 	printf("%c, %d\n", rang[i].first, rang[i].second);
// 	// }

// 	int ans = 0;
// 	rep(i,rang.size()){
// 		int e_ans = rang[i].second;
// 		while(rang[i].first == rang[i+1].first){
// 			e_ans += rang[++i].second;
// 		}
// 		ans += e_ans-1;
// 		// cout<<e_ans<<endl;
// 	}
// 	// cout<<ans<<endl;
// 	return ans;
// }

// int main(){
// 	cin>>N>>K>>s;
// 	vector<pair<char, int>> rang;
// 	rang.push_back(make_pair(s[0], 1));
// 	int i;
// 	for(i = 1; i<N; ++i){
// 		char c = rang[rang.size()-1].first;
// 		if(c != s[i]){
// 			rang.push_back(make_pair(s[i], 1));
// 		}else{
// 			rang[rang.size()-1].second++;
// 		}
// 	}
// 	cout<<rang.size()<<endl;
// 	int x = 0;
// 	rep(i,rang.size())x += rang[i].second;
// 	cout<<x<<endl;
// 	cout<<max({solve(rang, 'R', 0), solve(rang, 'R', 1), solve(rang, 'L', 0), solve(rang, 'L', 1)})<<endl;
// 	return 0;
// }
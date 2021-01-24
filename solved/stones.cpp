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
const ll MOD = 1e9 + 7;

int main(){
	int N; cin>>N;
	string s; cin>>s;
	vector<int> cnt_wht(N+1,0);
	vector<int> cnt_blk(N+1,0);
	rep(i,N)cnt_blk[i+1] = cnt_blk[i] + (s[i] == '#');
	for(int i = N-1; i>=0; --i)cnt_wht[i] = cnt_wht[i+1] + (s[i] == '.');
	int ans = inf;
	rep(i,N+1){
		ans = min(ans, cnt_wht[i] + cnt_blk[i]);
	}
	cout<<ans<<endl;
}

// int main(){
// 	int N; cin>>N;
// 	string s; cin>>s;
// 	int ans_1, ans_2, ans_3 = 0, ans_4 = 0;
// 	int cnt_blk = 0, cnt_wht = 0;
// 	rep(i,N){
// 		if(s[i] == '#') ++cnt_blk;
// 		else ++cnt_wht;
// 	}
// 	ans_1 = cnt_blk;
// 	ans_2 = cnt_wht;
// 	int ch_wht = 0;
// 	rep(i,N){
// 		if(ch_wht == cnt_wht)break;
// 		if(s[i] == '.') ++ch_wht;
// 		else ++ans_3;
// 	}
// 	int ch_blk = 0;
// 	for(int i = N-1; i>=0; --i){
// 		if(ch_blk == cnt_blk)break;
// 		if(s[i] == '#') ++ch_blk;
// 		else ++ans_4;
// 	}
// 	cout<<min({ans_1, ans_2, ans_3, ans_4})<<endl;
// 	return 0;
// }
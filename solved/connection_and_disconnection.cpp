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
const int MOD = (int)1e9 + 7;

int main(){
	string s; ll k; cin>>s>>k;
	int siz = s.size()-1;
	int seq_cnt = 0;
	//when 1-charactor
	if(s.size()==1){cout<<k/2<<endl; return 0;}

	for(int i = siz; i>=0; --i){
		if(s[siz] == s[i])seq_cnt++;
		else break;
	}
	//when all elements are same
	if(seq_cnt == s.size()){
		cout<<s.size()*k/2<<endl;
		return 0;
	}

	//others
	ll need_repl = 0;
	rep(i,s.size()-1){
		if(s[i] == s[i+1]){
			need_repl++;
			++i;
		}
	}
	int seq_cnt_h = 0;
	for(int i = 0; i<=siz; ++i){
		if(s[siz] == s[i])seq_cnt_h++;
		else break;
	}
	need_repl *= k;
	if((seq_cnt_h%2 && seq_cnt%2) && s[0] == s[siz]){
		need_repl += (k-1LL);
	}
	cout<<need_repl<<endl;
}

// int main(){
// 	string s; ll k; cin>>s>>k;
// 	if(s.size() == 1){
// 		cout<<k/2<<endl;
// 		return 0;
// 	}
// 	int cnt = 0;
// 	int ch = 0;
// 	rep(i,s.size()-1){
// 		if(s[i] == s[i+1]){++cnt; ++i; ch++; continue;}
// 		ch = 0;
// 	}
// 	bool ok = ((s[s.size()-1] != s[s.size()-2]) || ch%2);
// 	// cout<<ch<<' '<<ok<<endl;
// 	ll ans = cnt*k;
// 	if(s[0] == s[s.size()-1] && ok){
// 		ans += (k-1);
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }

// int main(){
// 	string s; ll k; cin>>s>>k;
// 	if(s.size() == 1){
// 		cout<<k/2<<endl;
// 		return 0;
// 	}
// 	// if(s.size() == 2){
// 	// 	if(s[0] == s[1]){
// 	// 		cout<<k<<endl;
// 	// 	}else{
// 	// 		cout<<0<<endl;
// 	// 	}
// 	// 	return 0;
// 	// }
// 	int cnt = 0;
// 	int ch = 0;
// 	rep(i,s.size()-1){
// 		if(s[i] == s[i+1]){++cnt; ++i; continue;}
// 	}
// 	for(int i = s.size()-1; i>=0; --i){
// 		if(s[i] == s[s.size()-1])ch ++;
// 		else break;
// 	}
// 	// cout<<cnt<<' '<<ch<<endl;
// 	// cout<<ch<<' '<<ok<<endl;
// 	ll ans = cnt*k;
// 	if(s[0] == s[s.size()-1] && ch%2){
// 		ans += (k-1);
// 	}
// 	if(k%2 && ch==s.size() && s.size()%2){
// 		cout<<(ll)s.size()*k-ans<<endl;
// 	}else{
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }
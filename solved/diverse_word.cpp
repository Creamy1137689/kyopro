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
	string s; cin>>s;
	int N = s.size();
	if(s == "zyxwvutsrqponmlkjihgfedcba"){cout<<-1<<endl; return 0;}
	if(N < 26){
		vector<int> chars(26,0);
		rep(i,N){
			int t = s[i] - 'a';
			chars[t] = 1;
		}
		char c;
		rep(i,26){
			if(chars[i] == 0){
				c = (char)('a'+i);
				break;
			}
		}
		cout<<s+c<<endl;
		return 0;
	}
	string ans = "zyxwvutsrqponmlkjihgfedcba";
	for(int k = 25; k> 0; --k){
		char c = s[k];
		int pos = k-1;
		int ok = inf;
		for(; pos>=0; --pos){
			if(s[pos]<c){
				ok = pos;
				break;
			}
		}
		if(ok != inf){
			string e_ans = s.substr(0,ok) + c;
			ans = min(ans, e_ans);
		}
	}
	cout<<ans<<endl;
	// char c = s[25];
	// int pos = 24;
	// for(; pos>=0; --pos){
	// 	if(s[pos]<c){
	// 		break;
	// 	}
	// }
	// cout<<s.substr(0,pos) + c<<endl;
	return 0;
}
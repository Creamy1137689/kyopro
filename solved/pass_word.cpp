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
	int hash = 0;
	rep(i,s.size())hash += s[i] - 'a' + 1;
	if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz"){cout << "NO" << endl; return 0;}
	if(s.size() == 1){
		string res = string((hash-2)/2, 'b') + string(2 + hash % 2, 'a');
		cout << res << endl;
		return 0;
	}
	set<char> st;
	rep(i,s.size())st.insert(s[i]);
	if(st.size() > 1){
		string res = s[s.size()-1] + s.substr(0, s.size()-1);
		cout << res << endl;
	}else{
		if(s[0] == 'a'){
			cout << (char)('a' + s.size()-1) << endl;
		}else if(s[0] == 'z'){
			cout << 'a' + s.substr(0, s.size()-1) + 'y' << endl; 
		}else{
			string res = s;
			res[0] = (char)(s[0]+1);
			res[1] = (char)(s[1]-1);
			cout << res << endl;
		}
	}
	return 0;
}

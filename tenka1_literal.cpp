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
	if(s == "{}"){
		cout << "dict" << endl;
		return 0;
	}
	int leftcnt = 0;
	string ans = "set";
	rep(i,s.size()){
		if(s[i] == '{') ++leftcnt;
		if(s[i] == '}') --leftcnt;
		if(leftcnt == 1 && s[i] == ':')ans = "dict";
	}
	cout << ans << endl;
	return 0;
}

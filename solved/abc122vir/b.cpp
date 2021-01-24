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

bool is_ok(string s){
	bool res = true;
	rep(i,s.size())if(!(s[i] == 'A' || s[i] == 'T' || s[i] == 'C' || s[i] == 'G'))res = false;
	return res;
}

int main(){
	string s;
	cin >> s;
	for(int i = s.size(); i > 0; --i){
		bool ok = true;
		for(int st = 0; st + i <= s.size(); ++st){
				string t = s.substr(st, i);
				if(is_ok(t)){
					cout << i << endl;
					return 0;
				}
		}
	}
	cout << 0 << endl;
	return 0;
}

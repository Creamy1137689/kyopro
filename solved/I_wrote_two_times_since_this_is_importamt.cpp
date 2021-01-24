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

string s, t;

bool is_num(char c){
	return ('0' <= c && c <= '9');
}

bool is_char(char c){
	return ('A' <= c && c <= 'Z');
}

void ch_char(char c, char n){
	rep(i,s.size())if(s[i] == c)s[i] = n;
	rep(i,t.size())if(t[i] == c)t[i] = n;
}

int main(){
	int N;
	cin >> N >> s >> t;
	bool done = false;
	while(!done){
		done = true;
		rep(i,N){
			if(is_num(s[i]) && is_char(t[i])){ ch_char(t[i], s[i]); done = false;}
			if(is_char(s[i]) && is_num(t[i])){ ch_char(s[i], t[i]); done = false;}
		}
	}
	done = false;
	while(!done){
		done = true;
		rep(i,N){
			if(s[i] != t[i] && is_char(s[i])){ ch_char(s[i], t[i]); done = false;}
		}
	}
	ll ans = 1;
	set<char> al;
	rep(i,N){
		if(is_char(s[i]) && al.count(s[i]) == 0){
			ans *= ((i == 0) ? 9 : 10);
			al.insert(s[i]);
		}
	}
	cout << ans << endl;
	return 0;
}

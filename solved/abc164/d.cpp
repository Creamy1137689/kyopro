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

vector<int> tasu(200200,0);

string plus_2019(string s){
	int siz = s.size()-1;
	int up = 1;
	for(int i = 0; i<s.size() && up == 1; ++i){
		char l = s[siz-i];
		int n = l-'0' + tasu[i] + up;
		if(n>=10){	
			s[siz-i] = (char)(n-10+'0');
			up = 1;
		}else{
			s[siz-i] = (char)(n+'0');
			up = 0;
		}
	}
	if(up == 1)return "1"+s;
	else return s;
}

bool com(string s, string t){
	if(s.size()>t.size())return true;
	if(s>t)return true;
	return false;
}

int main(){
	tasu[0] = 9;
	tasu[1] = 1;
	tasu[2] = 0;
	tasu[3] = 2;
	string s;
	cin>>s;
	ll ans = 0;
	string t = "2019";
	for(ll i = 2; com(s,t); ++i){
		for(int j = 0; j+t.size() <=s.size(); ++j){
			if(s.substr(j,t.size()) == t)++ans;
		}
		t = plus_2019(t);
	}
	cout<<ans<<endl;
	return 0;
}
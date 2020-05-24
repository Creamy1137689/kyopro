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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	string s;
	cin>>s;
	int ans = 0;
	bool ok = false;
	rep(i,s.size()){
		char op = s[i];
		if(op == '+'){
			if(!ok)ans++;
			ok = false;
		}
		if(op == '0')ok = true;
	}
	if(!ok)ans++;
	cout<<ans<<endl;
	return 0;
}

/*
int main(){
	string s;
	cin>>s;
	vector<ll> ele;
	ll rs = -1LL;
	rep(i,s.size()){
		char op = s[i];
		if(op == '+'){ele.push_back(rs); rs = -1LL; continue;}
		if(op == '*')continue;
		op -= '0';
		if(rs == -1LL)rs = (ll)op;
		else rs *= (ll)op;
	}
	ele.push_back(rs);
	int ans = 0;
	for(auto x: ele)if(x != 0LL)ans++;
	cout<<ans<<endl;
	return 0;
}*/
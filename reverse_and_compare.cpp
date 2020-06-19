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

string s = string(200000, 't');

//extract [l, r)
string divstr(int l, int r){
	return s.substr(l, r-l);
}

int main(){
	// cin>>s;
	int N = s.size();
	ll ans = s.size() * (s.size()+1) /2 + 1;
	queue<P> seed;
	rep(i,N){
		--ans;
		seed.push(make_pair(i, i+1));
	}
	rep(i,N-1){
		if(s[i] == s[i+1]){
			--ans;
			seed.push(make_pair(i, i+2));
		}
	}
	string t, p;
	while(!seed.empty()){
		int l = seed.front().first -1;
		int r = seed.front().second +1;
		seed.pop();
		if(0 <= l && r <= N){
			t = divstr(l,r);
			p = t;
			reverse(all(p));
			if(t == p){
				--ans;
				seed.push(make_pair(l, r));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
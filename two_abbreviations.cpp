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
	ll n,m; cin>>n>>m;
	string s,t; cin>>s>>t;
	ll g = n*m/__gcd(n,m);
	map<ll,char> check;
	// cout<<g<<endl;
	rep(i,n){
		ll pos = g/n * (ll)i;
		check[pos] = s[i];
	}
	rep(i,m){
		ll pos = g/m * (ll)i;
		if(check.count(pos) != 0){
			if(check[pos] != t[i]){
				cout<<-1<<endl; return 0;
			}
		}
	}
	cout<<g<<endl;
	return 0;
}
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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n; cin>>n;
	map<map<char,ll>,ll> r;
	rep(i,n){
		string s;
		cin>>s;
		map<char,ll> ss;
		rep(i,10){
			ss[s[i]]++;
		}
		r[ss]++;
	}
	ll ans = 0;
	for(auto x: r){
		ans += (x.second*(x.second-1))/2;
	}
	cout<<ans<<endl; return 0;
}

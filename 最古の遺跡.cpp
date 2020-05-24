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
#define all(x) begin(perm),end(perm)
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
	vector<ip> p(n);
	set<ip> ps;
	rep(i,n){
		cin>>p[i].first>>p[i].second;
		ps.insert(p[i]);
	}
	int ans = 0;
	rep(i,n){
		rep(j,n){
			if(i==j)continue;
			ip p1 = p[i], p2 = p[j];
			int dx = -p[i].first+p[j].first;
			int dy = -p[i].second+p[j].second;
			bool c = false, d = false;
			if(ps.count(make_pair(p2.first-dy, p2.second+dx)))c = true;
			if(ps.count(make_pair(p1.first-dy, p1.second+dx)))d = true;
			if(c&&d)ans = max(ans, dx*dx+dy*dy);
		}
	}
	cout<<ans<<endl; return 0;
}



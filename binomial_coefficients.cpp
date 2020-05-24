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
	int N; cin>>N;
	set<int> ele;
	int nax = 0;
	rep(i,N){
		int t; cin>>t;
		ele.insert(t);
		nax = max(nax, t);
	}
	ele.erase(nax);
	// show(ele);
	auto it1 = ele.upper_bound(nax/2);
	// cout<<*it1<<endl;
	auto it2 = it1;
	it2--;
	if(it1 == ele.end())it1 = it2;
	int ans = ((abs((double)nax/2-*it1) < abs((double)nax/2-*it2))?*it1:*it2);
	cout<<nax<<' '<<ans<<endl;
	return 0;
}
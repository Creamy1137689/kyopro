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
	vector<int> a(N), b(N);
	ll sum_a = 0, sum_b = 0;
	rep(i,N){cin>>a[i]; sum_a += a[i];}
	rep(i,N){cin>>b[i]; sum_b += b[i];}
	if(sum_a<sum_b){cout<<-1<<endl; return 0;}
	vector<int> excess;
	int ans = 0;
	ll s = 0;
	rep(i,N){
		if(a[i] < b[i]){++ans; s += (ll)(b[i]-a[i]);}
		else {excess.push_back(a[i]-b[i]);}
	}
	sort(all(excess), greater<int>());
	for(auto x:excess){
		if(s<=0)break;
		s -= x;
		ans ++;
	}
	cout<<ans<<endl;
	return 0;
}
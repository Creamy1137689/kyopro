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
	int N;cin>>N;
	ll abs_nin = INF;
	ll sum = 0;
	int cnt_minus = 0;
	rep(i,N){
		ll t; cin>>t;
		if(t<0) ++cnt_minus;
		sum += abs(t);
		abs_nin = min(abs_nin, abs(t));
	}
	cout<<((cnt_minus%2)?sum-abs_nin*2:sum)<<endl;
	return 0;
}
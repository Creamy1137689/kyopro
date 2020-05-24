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
	int x; cin>>x;
	int N = 1200;
	vector<ll> con(N);
	for(ll i = 0; i<=N; ++i){
		ll t = i*i*i*i*i;
		con[i] = t;
	}
	rep(i,N+1){
		rep(j,N+1){
			ll a = con[i];
			ll b = con[j];
			if(-a+b == (ll)x){cout<<-(i)<<' '<<-(j)<<endl; return 0;}
			if(a-b == (ll)x){cout<<(i)<<' '<<(j)<<endl; return 0;}
			if(a+b == (ll)x){cout<<(i)<<' '<<-(j)<<endl; return 0;}
			if(-a-b == (ll)x){cout<<-(i)<<' '<<(j)<<endl; return 0;}
		}
	}
	return 0;
}
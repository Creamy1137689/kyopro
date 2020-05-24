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
const ll MOD = 1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N; cin>>N;
	map<int,int> cnt;
	rep(i,N){
		int t; cin>>t;
		cnt[t]++;
	}
	bool ok = true;
	for(auto x: cnt){
		if(x.first == 0){
			if(x.second != 1)ok = false;
		}else{
			if(x.second != 2)ok = false;
		}
	}
	if(!ok){cout<<0<<endl; return 0;}
	int elm = cnt.size();
	if(N%2 == 1) --elm;
	cout<<rep_power_modM(2LL, elm, MOD)<<endl;;
	return 0;
}
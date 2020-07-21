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

int popcount(ll t){
	int res = 1;
	while(t > 0){
		ll k = t;
		int e_res = 0;
		while(k>0){
			if(k % 2 == 1)++e_res;
			k /= 2;
		}
		t %= e_res;
		++res;
	}
	return res;
}

ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	int N; cin>>N;
	string s; cin>>s;
	int p = 0, need;
	rep(i,N)if(s[i] == '1')++p;
	ll default_plus = 0, default_minus = 0;
	ll mp = p+1, mm = p-1;
	for(int i = 0; i<N; ++i){
		if(mp != 1)default_plus += rep_power_modM(2,i,mp)*(s[N-1-i] == '1');
		if(mm != 0)default_minus += rep_power_modM(2,i,mm)*(s[N-1-i] == '1');
		if(mp != 1)default_plus %= mp;
		if(mm != 0)default_minus %= mm;
	}
	rep(i,N){
		int res;
		if(s[i] == '1'){
			if(mm == 0){cout<<0<<endl; continue;}
			ll use = default_minus - rep_power_modM(2, N-1-i, mm);
			use %= mm;
			if(use < 0) use += mm;
			res = popcount(use);
		}else{
			if(mp == 1){cout<<1<<endl; continue;}
			ll use = default_plus + rep_power_modM(2, N-1-i, mp);
			use %= mp;
			if(use < 0)use += mp;
			res = popcount(use);
		}
		cout<<res<<endl;
	}
	return 0;
}
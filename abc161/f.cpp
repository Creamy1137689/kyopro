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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

map<ll, ll> prime_factor(ll n){
    map<ll,ll> com;
    for(ll i = 2LL; i*i<=n; ++i){
        while(n%i==0LL){
            com[i]++;
            n /= i;
        }
    }
    if(n != 1LL)com[n]++;
    return com;
}

int main(){
	ll N; cin>>N;
	// if(N==2){cout<<}
	ll ans = 1LL;
	// map<ll,ll> e1 = prime_factor(N-1LL);
	// ll t = 1LL;
	// for(auto x : e1){
	// 	t *= (x.second+1);
	// }
	ll M = N-1LL;
	for(ll div = 1LL; div*div<=M; ++div){
		if(M%div == 0){
			if(div*div == M)ans++;
			else ans += 2LL;
		}
	}
	ans--;
	// cout<<ans<<endl;
	for(ll k = 2LL; k*k <= N; ++k){
		if(N%k!=0)continue;
		ll tmp1 = N; ll tmp2 = N;
		ll l = N/k;
		while(tmp1%k==0)tmp1/=k; 
		if(tmp1%k == 1)ans++; 
		if(k==l)continue;
		while(tmp2%l==0)tmp2 /=l;
		if(tmp2%l == 1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}

// int main(){
// 	ll N;
// 	cin>>N;
// 	if(N==2LL){cout<<1<<endl; return 0;}
// 	if(N==3LL){cout<<2<<endl; return 0;}
// 	ll ans = 3LL;
// 	map<ll, ll> minus1 = prime_factor(N-1LL);
// 	if(minus1.size()!=1){
// 		ll addi = 1LL;
// 		for(auto x : minus1)addi *= (x.second+1);
// 		addi -= 2LL;
// 		if(minus1.count(2) != 0)addi--;
// 		ans += addi;
// 	}
// 	map<ll, ll> me = prime_factor(N);
// 	set<ll> t;
// 	ll cnt = 0LL;
// 	for(auto x : me){
// 		ll radi = x.first;
// 		REP(i,x.second){
// 			t.insert(pow(radi,i));
// 		}
// 		if(x.first != 2 &&x.second >=2LL)cnt+=x.second/2;
// 	}
	
// 	for(auto x: t){
// 		if(x == 2)continue;
// 		if(t.count(x+1))cnt++;
// 	}
// 	ans += cnt;
// 	cout<<ans<<endl;
// 	return 0;
// }
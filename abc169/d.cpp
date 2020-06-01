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
	set<ll> yakusuu;
	for(ll k = 1; k*k <=N; ++k){
		if(N%k == 0){
			yakusuu.insert(k);
			yakusuu.insert(N/k);
		}
	}
	int ans = 0;
	for(auto x: yakusuu){
		map<ll, ll> t = prime_factor(x);
		if(t.size() == 1){
			if(N<x){break;}
			if(N%x != 0){continue;}
			N /= x;
			ans ++;
			// printf("%lld, %lld\n", N, x);
		}

	}
	cout<<ans<<endl;
	return 0;
}
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
	int N; cin>>N;
	map<ll, ll> fact_cnt;
	for(int i = 1; i<=N; ++i){
		map<ll,ll> elm;
		elm = prime_factor(i);
		for(auto x:elm){
			fact_cnt[x.first] += x.second;
		}
	}
	ll ans = 1;
	for(auto x:fact_cnt){
		ans *= (x.second+1LL);
		ans %= MOD;
	}
	cout<<ans<<endl;
	return 0;
}
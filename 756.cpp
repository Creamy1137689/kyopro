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
	int N; 
	cin >> N;
	map<ll, ll> facts;
	REP(i,N){
		map<ll, ll> t = prime_factor(i);
		for(auto x:t){
			facts[x.first] += x.second;
		}
	}
	int ans = 0;
	//74
	for(auto x:facts){
		if(x.second >= 74) ++ans;
	}
	//2 * 24
	for(auto x:facts){
		for(auto y:facts){
			if(!(x.first < y.first))continue;
			if(x.second >= 2 && y.second >= 24) ++ans;
			if(x.second >= 24 && y.second >= 2) ++ans;
		}
	}
	//4*14
	for(auto x:facts){
		for(auto y:facts){
			if(!(x.first < y.first))continue;
			if(x.second >= 4 && y.second >= 14) ++ans;
			if(x.second >= 14 && y.second >= 4) ++ans;
		}
	}
	//2 * 4 * 4
	for(auto x: facts){
		for(auto y:facts){
			for(auto z: facts){
				if(!(x.first < y.first && y.first < z.first))continue;
				int a = (x.second >= 2) + (y.second >= 2) + (z.second >= 2);
				int b = (x.second >= 4) + (y.second >= 4) + (z.second >= 4);
				if(a >= 3 && b >= 3) ans += 3;
				else if(a >= 3 && b >= 2) ++ans;
			}
		}
	}
	//for(auto x: facts){
	//	printf("[%lld]->%lld.\n", x.first, x.second);
	//}
	cout << ans << endl;
	return 0;
}

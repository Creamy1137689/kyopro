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
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int P_MAX = 100101;
	vector<bool> primes(P_MAX,true);
	primes[1] = false;
	for(int i = 2; i<=P_MAX; ++i){
		if(primes[i]){
			for(int k = 2; i*k<=P_MAX; ++k){
				primes[i*k] = false;
			}
		}
	}

	int x; cin>>x;
	while(true){
		if(primes[x]){cout<<x<<endl; return 0;}
		++x;
	}
}

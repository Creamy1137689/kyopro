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
	vector<bool> primes(100100, true);
	primes[0] = false; primes[1] = false;
	for(int i = 2; i<100101; ++i){
		if(primes[i]){
			for(int k = 2; i*k<100101; ++k){
				primes[i*k]  = false;
			}
		}
	}
	vector<bool> islike(100100, false);
	for(int i = 3; i<100101; i += 2){
		if(primes[i]&& primes[(i+1)/2]){
			islike[i] = true;
		}
	}
	vector<int> count(100100, 0);
	REP(i,100100){
		count[i] = count[i-1] + (islike[i]);
	}
	int Q; cin>>Q;
	rep(i,Q){
		int l,r; cin>>l>>r;
		cout<<count[r]-count[l-1]<<endl;
	}
	return 0;
}
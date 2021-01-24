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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	vector<bool> primes(1000100, true);
	primes[0] = false; primes[1] = false;
	for(int i = 2; i < 1000100; ++i){
		if(primes[i] == false)continue;
		for(int j = 2; i*j < 1000100; ++j){
			primes[i*j] = false;
		}
	}	
	int N ;cin >> N;
	int ans = 1;
	int now = 0;
	int add = 7 % N;
	while(ans < 10000000){
		now *= 10;
		now += add;
		now %= N;
		if(now == 0){
			cout << ans << endl;
			return 0;
		}
		++ ans;
	}
	cout << -1 << endl;
	
 	return 0;
}

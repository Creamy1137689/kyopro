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

ll fact(ll k){
	ll res = 1;
	for(ll i = 1; i <= k; ++i){
		res *= i;
		res %= MOD;
	}
	return res;
}

int main(){
	int N;
	cin >> N;
	vector<int> t(N);
	map<int, int> cnt;
	rep(i,N){
		cin >> t[i];
		cnt[t[i]] ++;
	}
	ll time_sum = 0;
	ll time = 0;
	sort(all(t));
	rep(i,N){
		time += t[i];
		time_sum += time;
	}
	ll pattern = 1;
	for(auto x : cnt){
		pattern *= fact(x.second);
		pattern %= MOD;
		//printf("[%d]->%d\n", x.first, x.second);
	}
	if(pattern < 0)pattern += MOD;
	cout << time_sum << endl << pattern << endl;
	return 0;
}

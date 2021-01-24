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

int main(){
	ll A,B; cin>>A>>B;
	ll ans = 0;

	//1st-ditit
	ll hd = (A+3LL)/4*4;
	ll tl = B/4*4;
	ll fst = -1;
	for(ll i = A; i<=hd; ++i){ if(i%2 == 1)fst *= -1;}
	for(ll i = B; i>=tl; --i){ if(i%2 == 1)fst *= -1;}
	if(fst == 1) ++ans;

	//others
	for(ll bit = 1; pow(2,bit-1)<=B; ++bit){
		ll digit = pow(2,bit);
		ll h = (A+digit-1LL)/digit*digit;
		ll t = B/digit*digit;
		ll e_ans = 0;
		if(h / digit % 2 == 0){
			e_ans += h-A;
		}
		if(t / digit % 2 == 1){
			e_ans += B-t+1LL;
		}
		// printf("[digit, head, tail e_ans] -> [%lld, %lld, %lld, %lld]\n", digit, h, t, e_ans);
		if(e_ans % 2 == 1)ans += digit;
	}
	cout<<ans<<endl;
	return 0;
}
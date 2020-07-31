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

ll N, A, B;
vector<ll> h(1000000);

bool isOK(ll attack){
	ll al = B*attack;
	if(1e16 / B < attack)return true;
	ll need = 0LL;
	ll addi = A-B;
	rep(i,N){
		ll t = max(0LL, h[i]-al);
		need += t/addi + (t % addi != 0);
	}
	return ((need <= attack)?true:false);
}

ll binary_search(){
	ll ng = -1LL;
	ll ok = 100000000001000;
	while(abs(ok-ng) > 1LL){
		ll mid = (ok + ng)/2;
		if(isOK(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> N >> A >> B;
	h.resize(N);
	rep(i,N)cin >> h[i];
	cout << binary_search() << endl;
	return 0;
}

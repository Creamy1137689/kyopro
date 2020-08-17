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

ll N, K;
vector<ll> a(40000);
vector<ll> b(40000);
map<ll, ll> b_exist;

bool isOK(ll num){
	ll under_cnt = 0;
	ll same_cnt = 0;
	rep(i,N){
		ll need = num / a[i] + (num % a[i] != 0);
		bool same_on = (num % a[i] == 0);
		auto it = lower_bound(all(b), need);
		under_cnt += it - b.begin();
		if(same_on){
			same_cnt += b_exist[need];
		}
	}
	if(under_cnt >= K)return true;
	else{
		if(under_cnt + same_cnt >= K)return true;
		else return false;
	}
}

ll binary_search(){
	ll ng = 1;
	ll ok = 1e18 + 7;
	while(abs(ok-ng) > 1LL){
		ll mid = (ok + ng)/2LL;
		if(isOK(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> N >> K;
	a.resize(N); b.resize(N);
	rep(i,N){cin >> a[i];}
	rep(i,N){
		cin >> b[i];
		b_exist[b[i]] ++;
	}
	sort(all(a));
	sort(all(b));
	cout << binary_search() << endl;
	return 0;
}

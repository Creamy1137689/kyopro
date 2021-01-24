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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int n;
vector<lp> baloon(100100);

bool isOK(ll opt){
    vector<ll> check(n);
    rep(i,n){
    	if(opt < baloon[i].first)return false;
    	check[i] = (opt - baloon[i].first)/baloon[i].second;
    }
    sort(all(check));
    ll now = -1LL;
    rep(i,n){
    	if(now<check[i]){
    		now++;
    	}else{
    		return false;
    	}
    }
    return true;
}

ll binary_search(ll max_cost){
    ll ng = -1LL;
    ll ok = max_cost;
    while(abs(ok-ng) > 1LL){
        ll mid = (ok + ng)/2LL;
        if(isOK(mid))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	cin>>n;
	ll m = 0LL;
	rep(i,n){
		cin>>baloon[i].first>>baloon[i].second;
		m = max(m, baloon[i].first+(n-1LL)*baloon[i].second);
	}
	ll ans = binary_search(m);
	cout<<ans<<endl;
	return 0;
}
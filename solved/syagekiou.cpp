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

vector<ll> H(100100); 
vector<ll> S(100100); 
int N;

bool trial(ll h){
	vector<ll> need(N);
	rep(i,N){
		if(h < H[i])return false;
		need[i] = (h-H[i])/S[i];
	}
	sort(all(need));
	bool ok = true;
	rep(i,N){
		if(need[i] < i)ok = false;
	}
	return ok;
}

bool isOK(ll h){
    if(trial(h)) return true;
    else return false;
}

ll binary_search(ll nax){
    ll ng = -1;
    ll ok =nax;
    while(abs(ok-ng) > 1){
        ll mid = (ok + ng)/2;
        if(isOK(mid))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
	cin>>N;
	H.resize(N);
	S.resize(N);
	rep(i,N)cin>>H[i]>>S[i];
	cout<<binary_search(110000000000000)<<endl;
	return 0;
}
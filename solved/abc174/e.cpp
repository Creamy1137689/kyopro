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
vector<ll> A(200100);

bool isOK(ll len){
	ll cut_cnt = 0LL;
	rep(i,N){
		if(len >= A[i])continue;
		else cut_cnt += A[i]/len + (A[i]%len != 0LL) -1LL;
	}
	//printf("[len, cut_cnt -> %d, %d]\n", len, cut_cnt);
	if(cut_cnt <= K)return true;
	else return false;
}

ll binary_search(){
	ll ng = 0LL;
	ll ok = 10100000000;
	while(abs(ok-ng) > 1LL){
		ll mid = (ok + ng)/2LL;
		if(isOK(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> N >> K;
	A.resize(N);
	rep(i,N)cin >> A[i];
	cout << binary_search() << endl;
	return 0;
}

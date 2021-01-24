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
	int N;
	cin >> N;
	vector<ll> A(N+2, 0);
	vector<ll> T(N+2, 0);
	vector<ll> nax(N, INF);
	vector<bool> decided(N, false);
	REP(i,N)cin >> T[i];
	REP(i,N)cin >> A[i];
	rep(i,N){
		if(T[i+1] > T[i])decided[i] = true;
		nax[i] = T[i+1];
		nax[i] = min(nax[i], T[i+1]);
	}
	for(int i = N-1; i >= 0; --i){
		if(A[i+1] > A[i+2]){
			if((decided[i] && nax[i] != A[i+1]) || (!decided[i] && nax[i] < A[i+1])){
				cout << 0 << endl;
				return 0;
			}
			decided[i] = true;
		}
		nax[i] = min(nax[i], A[i+1]);
	}
	ll ans = 1;
	rep(i,N){
		if(decided[i] == false)ans *= nax[i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}

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

int main(){
	int N,K;cin>>N>>K;
	vector<double> exp(N);
	rep(i,N){
		double t;
		cin>>t;
		exp[i] = t*(t+1)/2 /t;
	}
	double ans = 0;
	rep(i,N-1)exp[i+1] += exp[i];
	ans = exp[K-1];
	for(int i = K; i<N; ++i){
		ans = max(ans, exp[i]-exp[i-K]);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}
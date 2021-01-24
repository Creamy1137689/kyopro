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

int main(){
	int N,M,X; cin>>N>>M>>X;
	vector<bool> nap(N+1, false);
	rep(i,M){
		int t; cin>>t;
		nap[t] = true;
	}
	int ans_a = 0;
	int ans_b = 0;
	for(int i = X; i<=N; ++i){
		if(nap[i])++ans_a;
	}
	for(int i = 0; i<=X; ++i){
		if(nap[i])++ans_b;
	}
	cout<<min(ans_a,ans_b)<<endl;
	return 0;
}
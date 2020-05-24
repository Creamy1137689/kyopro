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
	int N;
	ll ans_a = 0LL;
	// ll ans_b = 0LL;
	cin>>N;
	vector<ll> in(N);
	rep(i,N)cin>>in[i];
	rep(i,N){
		if(in[i] == i+1 && in[i+1] == i+2){
			ans_a ++;
			in[i] = i+2; in[i+1] = i+1;
		}	
	}
	rep(i,N){
		if(i%2 == 0){
			if(in[i] == i+1 || in[i+1] == i+2)ans_a ++;
		}
	}
	cout<<ans_a<<endl;
	return 0;
}
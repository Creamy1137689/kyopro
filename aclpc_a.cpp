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
#include <atcoder/all>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){	
	int N, Q, t, u, v;
	cin >> N >> Q;
	atcoder::dsu uf = atcoder::dsu(N);
	rep(i, Q){
		cin >> t >> u >> v;
		if(t == 0){
			uf.merge(u, v);
		}else{
			cout << ((uf.same(u,v)) ? "1"  : "0") << endl;
		}
	}
	return 0;
}

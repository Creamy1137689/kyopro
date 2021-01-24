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

int manhattan_dist(P from, P to){
	return abs(from.first - to.first) + abs(from.second - to.second);
}

int main(){
	int H, W, D, t;
	cin >> H >> W >> D;
	vector<P> point(H*W);
	REP(i,H){
		REP(j,W){
			cin >> t;
			--t;
			point[t] = make_pair(i,j);
		}
	}
	vector<ll> sum(H*W+1, inf);
	for(int i = 0; i < H*W; ++i){
		if(sum[i+1] != inf)break;
		sum[i+1] = 0;
		for(int j = 1; i+j*D < H*W; ++j){
			int to = i+j*D;
			int dist = manhattan_dist(point[to], point[to-D]);
			sum[to+1] = dist + sum[to-D+1];
		}
	}
	int Q, l, r;
	cin >> Q;
	rep(_,Q){
		cin >> l >> r;
		cout << sum[r] - sum[l] << endl;
	}
	return 0;
}

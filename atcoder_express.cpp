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

vector<vector<int>> G(600, vector<int>());

bool isOK(int st_num, int index, int key){
	if(G[st_num][index] <= key) return true;
	else return false;
}

int binary_search(int st_num, int nax, int key){
	int ng = nax;
	int ok = -1;
	while(abs(ok-ng) > 1){
		int mid = (ok + ng)/2;
		if(isOK(st_num,mid,key))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	int N, M, Q, l, r, p, q;
	cin >> N >> M >> Q;
	G.resize(N);
	rep(i,M){
		cin >> l >> r;
		--l; --r;
		G[l].push_back(r);
	}
	rep(i,N)sort(all(G[i]));
	rep(_,Q){
		cin >> p >> q;
		--p; --q;
		int res = 0;
		int key = q;
		for(int i = p; i <= q; ++i){
			int siz = G[i].size();
			res += binary_search(i, siz, key) + 1;
		}
		cout << res << endl;
	}
	return 0;
}

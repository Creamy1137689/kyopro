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

vector<int> D(100);
int N;

bool isOK(int nax){
	set<int> used;
	rep(i,N){
		int pivot;
		if(D[i] == 0 && used.count(0) == 1)return false;
		if(used.count(D[i]) == 0)pivot = D[i];
		else if(used.count(24-D[i]) == 0)pivot = 24 - D[i];
		else return false;
		rep(k, nax){
			int up = (pivot + k) % 24;
			int dw = pivot - k; if(dw < 0)dw += 24;
			used.insert(up);
			used.insert(dw);
		}
	}
	return true;
}

int binary_search(){
	int ng = 27;
	int ok = 0;
	while(abs(ok-ng) > 1){
		int mid = (ok + ng)/2;
		if(isOK(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> N;
	D.resize(N+1);
	rep(i,N)cin >> D[i];
	D[N] = 0;
	sort(all(D));
	++N;
	cout << binary_search() << endl;
	return 0;
}

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
	int H, W, M, a, b;
	cin >> H >> W >> M;
	vector<P> bomb(M);
	vector<int> hline(H, 0);
	vector<int> wline(W, 0);
	rep(i,M){
		cin >> a >> b;
		--a; --b;
		bomb[i] = make_pair(a,b);
		hline[a]++;
		wline[b]++;
	}
	int h_max = -1, w_max = -1;
	rep(i,H)h_max = max(h_max, hline[i]);
	rep(i,W)w_max = max(w_max, wline[i]);
	set<int> h_ok, w_ok;
	rep(i,H)if(hline[i] == h_max)h_ok.insert(i);
	rep(i,W)if(wline[i] == w_max)w_ok.insert(i);
	int cnt = 0;
	rep(i,M){
		if(h_ok.count(bomb[i].first) == 1 && w_ok.count(bomb[i].second) == 1) ++cnt; 
	}
	if(cnt == h_ok.size() * w_ok.size())cout << h_max + w_max -1 << endl;
	else cout << h_max + w_max << endl;
	return 0;
}

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
	vector<int> D(N);
	rep(i,N)cin >> D[i];
	D[N] = 0;
	if(N > 23){
		cout << 0 << endl;
		return 0;
	}
	int ans = -1;
	for(int bit = 0; bit < (1 << N); ++bit){
		vector<int> dist;
		dist.push_back(0);
		rep(i,N){
			if(D[i] == 0)dist.push_back(0);
			else if(bit & (1 << i)){
				dist.push_back(D[i]);
			}else{
				dist.push_back(24-D[i]);
			}
		}
		sort(all(dist));
		int e_ans = inf;
		for(int i = 0; i < dist.size()-1; ++i){
			e_ans = min(e_ans, dist[i+1] - dist[i]);
		}
		e_ans = min(e_ans, 24 - dist[dist.size()-1]);
		ans = max(e_ans, ans);
	}
	cout << ans << endl;
	return 0;
}

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
	int N, K;
	cin >> N >> K;
	int nax = (N-1)*(N-2)/2;
	if(!(K <= nax)){
		cout << -1 << endl;
		return 0;
	}
	int now = nax;
	vector<P> ans;
	bool end = false;
	for(int i = 2; i <= N; ++i)ans.push_back(make_pair(1, i));
	for(int i = 2; i <= N && !end; ++i){
		for(int j = i + 1; j <= N && !end; ++j){
			if(now == K){end = true; break;}
			ans.push_back(make_pair(i,j));
			--now;
		}
	}
	cout << ans.size() << endl;
	for(auto x:ans)cout << x.first << ' ' << x.second << endl;
	return 0;
}

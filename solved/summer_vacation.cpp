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
	int N, M, a, b;
	cin >> N >> M;
	vector<vector<int>> jobs(M+1, vector<int>());
	rep(i,N){
		cin >> a >> b;
		if(a > M)continue;
		jobs[a].push_back(b);
	}
	priority_queue<int> Q;
	ll ans = 0;
	for(int i = 1; i <= M; ++i){
		for(auto x:jobs[i]){
			Q.push(x);
		}
		if(!Q.empty()){
			ans += Q.top();
			Q.pop();
		}
	}
	cout << ans << endl;
}

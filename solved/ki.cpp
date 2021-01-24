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
#define show(obj) {for(auto x:obj)cout<<x+1<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N, a, b; cin >> N;
	vector<vector<int>> path(N, vector<int>());
	rep(i,N-1){
		cin >> a >> b;
		--a; --b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	vector<bool> al(N, false);
	vector<int> ans;	
	priority_queue<int, vector<int>, greater<int>> Q;
	Q.push(0);
	al[0] = true;
	while(!Q.empty()){
		int from = Q.top();
		Q.pop();
		ans.push_back(from);
		for(auto x: path[from]){
			if(!al[x]){
				al[x] = true;
				Q.push(x);
			}
		}
	}
	rep(i,N){
		cout << ans[i]+1;
		if(i != N-1)cout << ' ';
	}
	cout << endl;
	return 0;
}

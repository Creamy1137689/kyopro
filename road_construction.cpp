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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

vector<vector<int>> path(100100,vector<int>());
vector<bool> visited(100100,false);

void dfs(int s){
	visited[s] = true;
	for(auto x: path[s]){
		if(!visited[x]){
			dfs(x);
		}
	}
	return ;
}

int main(){
	int N,M,a,b; cin>>N>>M;
	rep(i,M){
		cin>>a>>b;
		--a; --b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	int ans = 0;
	rep(i,N){
		if(!visited[i]){
			++ans;
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
	return 0;
}
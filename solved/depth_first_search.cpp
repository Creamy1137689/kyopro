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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int t = 0;
vector<vector<int>> graph(110);
vector<ip> ans(110,make_pair(-1,-1));

void dfs(int index){
	if(ans[index].first==-1)ans[index].first = ++t;
	else return ;
	if(graph[index].size()==0){
		if(ans[index].second == -1){
			ans[index].second = ++t;
		}
		return;
	}
	rep(i,graph[index].size()){
		dfs(graph[index][i]);
	}
	if(ans[index].second == -1){
		ans[index].second = ++t;
	}
	return ;
}

int main(){
	int n;
	cin>>n;
	REP(i,n){
		int cnt;
		cin>>cnt>>cnt;
		vector<int> pp(cnt);
		rep(j,cnt){
			cin>>pp[j];
		}
		graph[i] = pp;
	}
	REP(i,n){
		if(ans[i].first==-1)dfs(i);
	}
	REP(i,n){
		cout<<i<<' '<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}
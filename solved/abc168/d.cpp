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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N,M; cin>>N>>M;
	vector<int> room(N,inf);
	vector<vector<int>> path(N, vector<int>());
	rep(i,M){
		int a,b; cin>>a>>b;
		--a; --b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	queue<int> Q;
	room[0] = -1;
	Q.push(0);
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		for(auto x:path[node]){
			if(room[x] != inf)continue;
			room[x] = node;
			Q.push(x);
		}
	}
	bool ok = true;
	rep(i,N)if(room[i] == inf)ok = false;
	if(ok == false){cout<<"No"<<endl; return 0;}
	cout<<"Yes"<<endl;
	for(int i = 1; i<N; ++i)cout<<room[i]+1<<endl;
	return 0;
}

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

int main(){
	int N,P;
	cin>>N>>P;
	vector<int> ans(N,inf);
	vector<vector<int>> node(N, vector<int>());
	vector<int> value(N,0);
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		--a; --b;
		node[a].push_back(b); 
		node[b].push_back(a);
	}
	rep(i,P){
		int p,x;
		cin>>p>>x;
		value[--p] += x;
	}
	queue<int> Q;
	Q.push(0);
	ans[0] = 0;
	while(!Q.empty()){
		int n = Q.front();
		ans[n] += value[n];
		Q.pop();
		for(auto x: node[n]){
			if(ans[x] == inf){
				ans[x] = ans[n];
				Q.push(x);
			}
		}
	}
	for(auto x : ans)cout<<x<<' ';
		cout<<endl;
	return 0;
}
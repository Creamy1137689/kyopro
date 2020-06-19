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

int main(){
	int N,M; cin>>N>>M;
	vector<vector<bool>> path(N, vector<bool> (N,false));
	rep(i,M){
		int a, b; 
		cin>>a>>b;
		--a; --b;
		path[a][b] = true;
		path[b][a] = true;
	} 
	rep(i,N){
		queue<int> Q;
		set<int> fr;
		rep(j,N){
			if(path[i][j])Q.push(j);
		}
		while(!Q.empty()){
			int t = Q.front();
			Q.pop();
			rep(j,N){
				if(path[t][j])fr.insert(j);
			}
		}
		rep(j,N){
			if(path[i][j])fr.erase(j);
		}
		fr.erase(i);
		cout<<fr.size()<<endl;
	}
	return 0;
}
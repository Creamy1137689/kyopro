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
	vector<vector<int>> path(N,vector<int>());
	rep(i,N-1){
		int a,b;
		cin >> a >> b;
		--a;
		--b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	queue<int> Q;
	int x;
	int max_x = -1;
	vector<int> dist_x(N,inf);
	dist_x[0] = 0;
	Q.push(0);
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto t:path[f]){
			if(dist_x[t] == inf){
				dist_x[t] = dist_x[f] + 1;
				if(dist_x[t] > max_x){
					max_x = dist_x[t];
					x = t;
				}
				Q.push(t);
			}
		}
	}

	vector<int> dist_y(N,inf);
	int y, max_y = -1;
	dist_y[x] = 0;
	Q.push(x);
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto t:path[f]){
			if(dist_y[t] == inf){
				dist_y[t] = dist_y[f] + 1;
				if(dist_y[t] > max_y){
					max_y = dist_y[t];
					y = t;
				}
				Q.push(t);
			}
		}
	}
	cout << x+1 << ' ' << y+1 << endl;
	return 0;
}

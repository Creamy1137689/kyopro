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
#define show(obj) {for(auto x:obj)cout<<x<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N;cin>>N;
	vector<int> cnt(N,0);
	vector<ip> edge(N-1);
	vector<vector<int>> G(N,vector<int>());
	rep(i,N-1){
		int a,b; cin>>a>>b;
		--a; --b;
		++cnt[a]; ++cnt[b];
		edge[i] = make_pair(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int color = 0;
	int root = 0;
	rep(i,N){
		if(cnt[i]>color){
			color = cnt[i];
			root = i;
		}
	}
	queue<int> Q;
	map<ip,int> ans;
	vector<int> al(N,inf);
	Q.push(root);
	al[root] = 0;
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		int col = 0;
		rep(i,G[f].size()){
			int t = G[f][i];
			if(al[t] == inf){
				++col;
				if(col == al[f])++col;
				ans[make_pair(f, t)] = col;
				al[t] = col;
				Q.push(t);
			}
		}
	}
	cout<<color<<endl;
	rep(i,N-1){
		cout<<max(ans[edge[i]], ans[make_pair(edge[i].second, edge[i].first)])<<endl;
	}
}

// int main(){
// 	int N;cin>>N;
// 	vector<int> cnt(N,0);
// 	vector<ip> edge(N-1);
// 	rep(i,N-1){
// 		int a,b; cin>>a>>b;
// 		--a; --b;
// 		++cnt[a]; ++cnt[b];
// 		edge[i] = make_pair(a, b);
// 	}
// 	int color = 0;
// 	rep(i,N)color = max(color, cnt[i]);
// 	vector<int> ans(N-1,inf);
// 	vector<vector<int>> sett(N,vector<int>(color,0));
// 	queue<int> Q;
// 	cout<<color<<endl;
// 	rep(i,N-1){
// 		int f = edge[i].first, t = edge[i].second;
// 		rep(k,color){
// 			if(sett[f][k]==0 && sett[t][k] == 0){
// 				ans[i] = k+1;
// 				sett[f][k] = 1;
// 				sett[t][k] = 1;
// 				break;
// 			}
// 		}
// 		// cout<<"["<<i<<"]: ";
// 		// show(sett);
// 	}
	
// 	show(ans);
// 	return 0;
// }
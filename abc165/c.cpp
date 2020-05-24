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
const int MOD = (int)1e9 + 7;

ll ans = 0;
int N,M,Q;
struct query{
	int a;
	int b;
	int dis;
	int score;
};
vector<query> que(60);

void dfs(vector<int> a){
	int siz = a.size();
	if(siz==N){
		ll e_ans = 0;
		rep(i,Q){
			if(a[que[i].b]-a[que[i].a] == que[i].dis){
				e_ans += que[i].score;
			}
		}
		ans = max(ans, e_ans);
		return ;
	}
	for(int i = a[siz-1]; i<=M; ++i){
		vector<int> b = a;
		b.push_back(i);
		dfs(b);
	}
	return ;
}

int main(){
	cin>>N>>M>>Q;
	rep(i,Q){
		cin>>que[i].a; --que[i].a;
		cin>>que[i].b; --que[i].b;
		cin>>que[i].dis;
		cin>>que[i].score;
	}
	for(int i = 1; i<=M; ++i){
		vector<int> a = {i};
		dfs(a);
	}
	cout<<ans<<endl;
	return 0;
}
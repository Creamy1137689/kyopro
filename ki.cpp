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

vector<ll> tree[200200];
vector<ll> ans(200200, 0);
vector<bool> al(200200, false);

void dfs(ll p, ll plus){
	ans[p] += plus;
	al[p] = true;
	if(tree[p].size()==0)return ;
	rep(i,tree[p].size()){
		if(al[tree[p][i]])continue;
		dfs(tree[p][i], ans[p]);
	}
	return ;
}

int main(){
	ll n,q;
	cin>>n>>q;
	rep(i,n-1){
		ll a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	rep(i,q){
		ll p,x;
		cin>>p>>x;
		ans[p] += x;
	}
	dfs(1,0LL);
	REP(i,n)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
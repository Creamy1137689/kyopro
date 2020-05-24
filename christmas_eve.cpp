#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<vector<bool>> garden(110,vector<bool> (110,false));
int n;

void dfs(int i, int j){
	if(i>=n)return ;
	if(!garden[i][j])return ;
	garden[i][j] = false;
	dfs(i+1, j);
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> h(n);
	rep(i,n){
		cin>>h[i];
	}
	sort(all(h));
	int ans = inf;
	for(int i = 0; i+k-1<n; ++i){
		ans = min(ans, h[i+k-1]-h[i]);
	}
	cout<<ans<<endl; return 0;
}

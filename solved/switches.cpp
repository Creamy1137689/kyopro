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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n,m; cin>>n>>m;
	vector<vector<int>> array(m,vector<int>());
	rep(i,m){
		int k; cin>>k;
		vint e(k);
		rep(j,k){cin>>e[j]; e[j]--;}
		array[i] = e;
	}
	vector<int> cond(m);
	rep(i,m)cin>>cond[i];
	int ans = 0;
	for(int bit = 0; bit<(1<<n); ++bit){
		vector<bool> onof(m,false);
		for(int i = 0; i<n; ++i){
			if(bit & (1<<i)){
				onof[i] = true;
			}
		}
		bool ok = true;
		rep(i,m){
			int cnt = 0;
			rep(j,array[i].size()){
				if(onof[array[i][j]])cnt++;
			}
			if(cnt%2==cond[i]);
			else{ ok = false; break;}
		}
		if(ok)ans++;
	}
	cout<<ans<<endl; return 0;
	return 0;
}
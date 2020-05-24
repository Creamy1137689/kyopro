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
	int n,m;
	cin>>n>>m;
	vector<vector<ip>> pre(n,vector<ip>());
	vector<pair<int,pair<int,int>>> ans;
	REP(i,m){
		int p,y;
		cin>>p>>y;
		pre[--p].push_back(make_pair(y, i));
	}
	rep(i,n)sort(all(pre[i]));
	rep(i,n){
		int cnt = pre[i].size();
		rep(j,cnt){
			ip address = make_pair(i+1, j+1);
			ans.push_back(make_pair(pre[i][j].second, address));
		}
	}
	sort(all(ans));
	rep(i,m){
		printf("%06d%06d\n",ans[i].second.first,ans[i].second.second);
	}
}

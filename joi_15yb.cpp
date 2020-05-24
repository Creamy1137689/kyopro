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

int main(){
	int N,M;
	cin>>N>>M;
	vector<int> tar(M);
	vector<int> ans(N,0);
	rep(i,M)cin>>tar[i];
	rep(i,M){
		vector<int> exp(N);
		int cr_cnt = 0;
		rep(j,N){
			int t; cin>>t;
			if(t == tar[i]){
				++ans[j];
				++cr_cnt;
			}
		}
		ans[--tar[i]] += N-cr_cnt;
	}
	rep(i,N)cout<<ans[i]<<endl;
	return 0;
}
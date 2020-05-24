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
	int N,M; cin>>N>>M;
	vector<int> cost(N);
	vector<int> base(M);
	rep(i,N)cin>>cost[i];
	rep(i,M)cin>>base[i];
	vector<int> vote(N,0);
	rep(i,M){
		int t = base[i];
		rep(j,N){
			if(cost[j] <= t){
				++vote[j];
				break;
			}
		}
	}
	int nax = 0;
	int ans = 0;
	rep(i,N)if(nax < vote[i]){nax = vote[i]; ans = i;}
	cout<<ans+1<<endl;
	return 0;
}
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
	int N;cin>>N;
	vector<int> bar(N+1); bar[0] = inf;
	rep(i,N)cin>>bar[i+1];
	set<int> val; val.insert(inf);
	int right = 0;
	bool ok = true;
	int er_need = inf;
	int ans = 0;
	for(int i = 1; i<=N; ++i){
		if(bar[i-1] == er_need){
			ok = true;
		}else{
			val.erase(bar[i-1]);
		}
		while(ok && right <= N){
			++right;
			if(val.count(bar[right]) == true){
				ok = false;
				er_need = bar[right];
			}
			val.insert(bar[right]);
		}
		// cout<<er_need<<endl;
		ans = max(ans, right - i);
	}
	cout<<ans<<endl;
	return 0;
}
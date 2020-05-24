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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main(){
	int N,T; cin>>N>>T;
	vector<P> task(N);
	rep(i,N)cin>>task[i].first>>task[i].second;
	int nin = 0;
	rep(i,N)nin += task[i].second;
	if(nin>T){cout<<-1<<endl; return 0;}
	int rest = T-nin;
	vector<int> ext(N);
	rep(i,N)ext[i] = task[i].first-task[i].second;
	int ans = N;
	sort(all(ext));
	for(int i = 0; i<N; ++i){
		if(rest<ext[i])break;
		rest -= ext[i];
		--ans;
	}
	cout<<ans<<endl;
	return 0;
}
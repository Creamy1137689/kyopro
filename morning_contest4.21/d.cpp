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
	int N; cin>>N;
	vector<int> mt(N);
	rep(i,N)cin>>mt[i];
	int ans = 0;
	int s = 0;
	bool up,down;
	if(mt[0]>mt[1]){up = false; down = true;}
	else {up = true; down = false;}
	REP(i,N-1){
		if(mt[i]>mt[i-1] && up)continue;
		if(mt[i]<mt[i-1] && up){
			down = true; up = false;
		}
		if(mt[i]<mt[i-1] && down)continue;
		if(mt[i]>mt[i-1] && down){
			ans = max(ans, i-s+1);
			s = i;
			down = false; up = true;
		}
	}
	ans = max(ans,N-s);
	cout<<ans<<endl;
	return 0;
}
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
	int N; cin>>N;
	vector<int> in(N);
	vector<int> R;
	rep(i,N)cin>>in[i];
	rep(i,N){
		if(i == 0)R.push_back(in[0]);
		else{
			if(R[R.size()-1] != in[i])R.push_back(in[i]);
		}
	}
	int ans = 0;
	for(int i = 0; i<(int)R.size()-2; ++i){
		cout<<i<<endl;
		if(R[i] > R[i+1] && R[i+1] < R[i+2])++ans;
		if(R[i] < R[i+1] && R[i+1] > R[i+2])++ans;
	}
	if(ans > 0)ans += 2;
	cout<<ans<<endl;
	return 0;
}
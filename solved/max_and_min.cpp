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
	vector<int> dis(N);
	rep(i,N)cin>>dis[i];
	int ans_max = 0;
	int arm_max = 0;
	rep(i,N){
		ans_max += dis[i];
		arm_max = max(arm_max, dis[i]);
	}
	int ans_min = arm_max;
	if(N != 1)ans_min = max(0, arm_max - ans_max + arm_max);
	cout<<ans_max<<endl<<ans_min<<endl;
	return 0;
}
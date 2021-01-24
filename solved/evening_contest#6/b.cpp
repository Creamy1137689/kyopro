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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

struct st{
	int x;
	int y;
	int time;
};

int main(){
	int N;
	cin>>N;
	vector<st> plan(N+1);
	plan[0].x = 0; plan[0].y = 0;
	plan[0].time = 0;
	REP(i,N)cin>>plan[i].time>>plan[i].x>>plan[i].y;
	bool ok = true;
	REP(i,N){
		int t = plan[i].time - plan[i-1].time;
		int dis = abs(plan[i].x - plan[i-1].x) + abs(plan[i].y - plan[i-1].y);
		if(t<dis)ok = false;
		if(t % 2 != dis % 2)ok = false;
	}
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}
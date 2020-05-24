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

int main(){
	int N;
	cin>>N;
	int bf_x = 0, bf_y = 0, bf_t = 0;
	bool ok = true;
	rep(i,N){
		int x,y,t;
		cin>>t>>x>>y;
		int dist = abs(x-bf_x) + abs(y-bf_y);
		int time = t-bf_t;
		if(dist > time){ok = false;}
		if(dist < time && dist%2 != time%2){ok = false;}
		bf_x = x; bf_y = y; bf_t = t;
	}
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}
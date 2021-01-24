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
	int N,K;
	cin>>N>>K;
	vector<int> input(N);
	rep(i,N)cin>>input[i];
	int g = 0;
	rep(i,N)g = __gcd(g,input[i]);
	string ans = "IMPOSSIBLE";
	rep(i,N){
		int dis = input[i]-K;
		if(dis<0)continue;
		if(dis%g == 0)ans = "POSSIBLE";
	}
	cout<<ans<<endl;
	return 0;
}

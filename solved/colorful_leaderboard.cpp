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
	vector<bool> colors(8);
	int additional = 0;
	rep(i,N){
		int rate;
		cin>>rate;
		if(rate>=3200){
			additional++;
			continue;
		}
		colors[rate/400] = true;
	}
	int ans = 0;
	rep(i,8)if(colors[i])ans++;
	cout<<ans+((ans==0)?1:0)<<' '<<ans+additional<<endl;
	return 0;
}
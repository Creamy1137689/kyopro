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
	int n;
	cin>>n;
	vector<ip> town(n);
	rep(i,n)cin>>town[i].first>>town[i].second;
	int perm[8] = {0,1,2,3,4,5,6,7};
	double ans = 0;
	int cnt = 0;
	do{
		++cnt;
		rep(i,n-1){
			double x = pow((town[perm[i]].first - town[perm[i+1]].first),2);
			double y = pow((town[perm[i]].second - town[perm[i+1]].second),2);
			ans += sqrt(x+y);
		}
	}while(next_permutation(perm, perm+n));
	cout<<fixed<<setprecision(10)<<ans/cnt<<endl;
	return 0;
}

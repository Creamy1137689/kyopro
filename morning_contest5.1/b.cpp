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

double dis(ip a, ip b){
	double x = abs(a.first-b.first);
	double y = abs(a.second-b.second);
	return sqrt(x*x + y*y);
}

int main(){
	int N; cin>>N;
	double ans = 0;
	int perm[8] = {0,1,2,3,4,5,6,7};
	vector<ip> town(N);
	rep(i,N)cin>>town[i].first>>town[i].second;
	do{
		rep(i,N-1){
			ans += dis(town[perm[i]], town[perm[i+1]]);
		}
	}while(next_permutation(perm, perm+N));
	int div = 1;
	REP(i,N)div *= i;
	cout<<fixed<<setprecision(10)<<ans/div<<endl;
	return 0;
}
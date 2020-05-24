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

double power(int t, int s){
	return (t-s)*(t-s);
}

int main(){
	int N;cin>>N;
	vector<ip> town(N);
	rep(i,N)cin>>town[i].first>>town[i].second;
	int perm[8] = {0,1,2,3,4,5,6,7};
	double ans = 0;
	int divisor = 0;
	do{
		++divisor;
		for(int i = 0; i<N-1; ++i){
			ans += sqrt(power(town[perm[i]].first, town[perm[i+1]].first) + power(town[perm[i]].second, town[perm[i+1]].second));
		}
	}while(next_permutation(perm, perm+N));
	cout<<fixed<<setprecision(10)<<ans/divisor<<endl;
	return 0;
}
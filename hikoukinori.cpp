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
	int N, M, X, Y; 
	cin>>N>>M>>X>>Y;
	vector<int> a(N);
	vector<int> b(M);
	rep(i,N)cin>>a[i];
	rep(i,M)cin>>b[i];
	int ans = 0;
	ll nt = 0;
	while(true){
		auto it = lower_bound(all(a), nt);
		if(it == a.end())break;
		nt = *it; nt += X;
		it = lower_bound(all(b), nt);
		if(it == b.end())break;
		nt = *it; nt += Y;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}
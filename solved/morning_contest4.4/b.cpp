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
	vector<int> a(100010);
	int nax = -1;
	rep(i,N){
		int t;
		cin>>t;
		a[t]++;
		nax = max(nax, t);
	}
	int ans = 0;
	for(int i = 1; i<100010; i++){
		ans = max(a[i] + a[i-1] + a[i+1], ans);
	}
	cout<<ans<<endl;
	return 0;
}
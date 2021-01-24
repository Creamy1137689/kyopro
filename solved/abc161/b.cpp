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
	int N,M;
	cin>>N>>M;
	vector<int> a(N);
	int sum = 0;
	rep(i,N){cin>>a[i]; sum += a[i];}
	sort(all(a));
	bool ok = true;
	for(int i = 0; i<M; ++i){
		if(a[N-1-i]*4*M < sum){ok = false; break;}
	}
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}
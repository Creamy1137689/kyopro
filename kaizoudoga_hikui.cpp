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
	int N,K;
	cin>>N>>K;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int ans = 0;
	int now = 0;
	rep(i,N-1){
		now++;
		if(A[i] >= A[i+1]){
			ans += max(0, now-K + 1);
			now = 0;
		}
	}
	if(A[N-2] < A[N-1])++now;
	ans += max(0, now-K + 1);
	cout<<ans<<endl;
	return 0;
}
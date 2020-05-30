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
	int N; cin>>N;
	vector<int> A(N);
	rep(i,N){
		cin>>A[i];
		A[i] -= i+1;
	}
	sort(all(A));
	if(N%2 == 1){
		ll ans = 0;
		int medi = A[N/2];
		rep(i,N){
			ans += abs(A[i] - medi);
		}
		cout<<ans<<endl;
	}else{
		ll ans_a = 0, ans_b;
		int medi_a = A[N/2], medi_b = A[N/2-1];
		rep(i,N){
			ans_a += abs(A[i] - medi_a);
			ans_b += abs(A[i] - medi_b);
		}
		cout<<min(ans_a, ans_b)<<endl;
	}
	return 0;
}
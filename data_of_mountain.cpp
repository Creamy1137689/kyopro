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
	vector<int> h(N);
	vector<bool> sp(N,false);
	rep(i,N)cin>>h[i];
	rep(i,N-2){
		if(h[i] > h[i+1] && h[i+1] < h[i+2]){
			sp[i+1] = true;
		}
	}
	int ans = 0;
	int e_ans = 0;
	rep(i,N){
		++e_ans;
		if(sp[i]){
			ans = max(ans, e_ans);
			e_ans = 1;
		}
	}
	ans = max(ans, e_ans);
	cout<<ans<<endl;
	return 0;
}
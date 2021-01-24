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
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N; cin>>N;
	REP(i,N){
		int e_ans = 0;
		for(int x = 1; x*x <= i; ++x){
			int dbx = x*x;
			for(int y = 1; dbx + y*y <= i; ++y){
				int dby = y*y;
				int rest = i - dbx - dby - x*y;
				double t = x+y;
				double kai = (double)(-t + sqrt(t*t + 4*rest))/2;
				if(kai == floor(kai) && kai > 0)++e_ans;
				// for(int k = 1; k*k <= rest; ++k){
				// 	if(rest % k == 0){
				// 		if(abs(k - rest/k) == x+y)++e_ans;
				// 	}
				// }
			}
		}
		cout<<e_ans<<endl;
	}
	return 0;
}
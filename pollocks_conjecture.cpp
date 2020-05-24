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

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}




int main(){
	vector<int> dp1(1000100,inf);
	vector<int> dp2(1000100,inf);
		vector<int> opt1;
		vector<int> opt2;
		for(int i = 1; i*(i+1)*(i+2) <= 6*1000000; ++i){
			int t = i*(i+1)*(i+2)/6;
			opt1.push_back(t);
			if(t%2)opt2.push_back(t);
		}
		dp1[0] = 0;
		dp2[0] = 0;
		REP(i,1000100){
			rep(j,opt1.size()){
				if(opt1[j]>i)continue;
				chmin(dp1[i], dp1[i-opt1[j]]+1);
			}
		}
		REP(i,1000100){
			rep(j,opt2.size()){
				if(opt2[j]>i)continue;
				chmin(dp2[i], dp2[i-opt2[j]]+1);
			}
		}
		// REP(i,opt1.size()-1){
		// 	REP(j,N){
		// 		if(opt1[i]>j){
		// 			chmin(dp1[i][j], dp1[i-1][j]);
		// 		}else{
		// 			chmin(dp1[i][j], dp1[i-1][j]);
		// 			chmin(dp1[i][j], dp1[i-1][j-opt1[i]]+1);
		// 			chmin(dp1[i][j], dp1[i][j-opt1[i]]+1);
		// 		}
		// 	}
		// }
		// REP(i,opt2.size()-1){
		// 	REP(j,N){
		// 		if(opt2[i]>j){
		// 			chmin(dp2[i][j], dp2[i-1][j]);
		// 		}else{
		// 			chmin(dp2[i][j], dp2[i-1][j]);
		// 			chmin(dp2[i][j], dp2[i-1][j-opt2[i]]+1);
		// 			chmin(dp2[i][j], dp2[i][j-opt2[i]]+1);
		// 		}
		// 	}
		// }
		// ans1 = dp1[opt1.size()-1][N];
		// ans2 = dp2[opt2.size()-1][N];
		int N;
		int ans1, ans2;
		while(true){
			scanf("%d",&N);
			if(!N)break;
			ans1 = dp1[N]; ans2 = dp2[N];
			printf("%d %d\n",ans1,ans2);
		}
	return 0;
}
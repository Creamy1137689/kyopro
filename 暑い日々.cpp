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

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

struct cloth{
	int a;
	int b;
	int c;
};

int D,N;
vector<int> T(220);
vector<cloth> cl(220);

bool ok(cloth P, cloth Q, int day){
	bool ans = true;
	if(P.a > T[day-1])ans = false;
	if(P.b < T[day-1])ans = false;
	if(Q.a > T[day])ans = false;
	if(Q.b < T[day])ans = false;
	return ans;
}

int main(){
	cin>>D>>N;
	rep(i,D)cin>>T[i];
	rep(i,N)cin>>cl[i].a>>cl[i].b>>cl[i].c;
	int dp[220][220] = {0};
	for(int i = 1; i<D; ++i){
		rep(j,N){
			rep(k,N){
				if(ok(cl[k],cl[j],i)){
					//printf("[Day:%d] %d & %d\n", i, j,k);
					chmax(dp[i][j], dp[i-1][k] + abs(cl[k].c - cl[j].c));
					//cout<<dp[i][j]<<endl;
				}
			}
		}
	}
	int ans = 0;
	rep(i,N)chmax(ans, dp[D-1][i]);
	cout<<ans<<endl;
	return 0;
}
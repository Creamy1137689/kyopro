#include <iostream>
#include <fstream>
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
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int point(int base, int sub){
	int ans = base+sub;
	if(ans>255)return 255;
	else if(ans <0)return 0;
	else return ans;
}

int x2(int a, int b){
	return (a-b)*(a-b);
}

int main(){
	int N,M;
	ofstream outputfile("ans.txt");
	while(true){
		cin>>N>>M;
		if(!N && !M)break;
		vector<int> C(M);
		vector<int> Y(N);
		rep(i,M)cin>>C[i];
		rep(i,N)cin>>Y[i];
		vector<vector<int>> dp(N, vector<int>(256,inf));
		rep(i,M){
			int p = point(128, C[i]);
			dp[0][p] = x2(p, Y[0]);
		}
		for(int i = 0; i<N-1; ++i){
			rep(j,256){
				if(dp[i][j] == inf)continue;
				// printf("[%d] -> %d\n", j, dp[i][j]);
				// cout<<"----"<<j<<"----"<<endl;
				rep(k,M){
					int p = point(j, C[k]);
					// cout<<p<<endl;
					chmin(dp[i+1][p], dp[i][j] + x2(p,Y[i+1]));
				}
			}
		}
		int ans = inf;
		rep(i,256)chmin(ans, dp[N-1][i]);
		// cout<<"---------"<<endl;
		cout<<ans<<endl;
		// cout<<"---------"<<endl;
		outputfile<<ans<<'\n';
	}
	outputfile.close();
	return 0;
}

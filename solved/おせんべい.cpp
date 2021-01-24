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
	int r,c;
	cin>>r>>c;
	vector<vector<int>> ma(r,vector<int>(c));
	rep(i,r)rep(j,c)cin>>ma[i][j];
	int ans = inf;
	for(int bit = 0; bit<(1<<r); ++bit){
		vector<vector<int>> cir(r,vector<int>(c));
		rep(i,r){
			if(bit & (1<<i)){
				rep(j,c)cir[i][j] = !ma[i][j];
			}else{
				rep(j,c)cir[i][j] = ma[i][j];
			}
		}
		int t = 0;
		rep(j,c){
			int cnt_0 = 0;
			rep(i,r){
				if(cir[i][j] == 0)cnt_0++;
			}
			if(cnt_0 < (r+1)/2){
				t += cnt_0;
			}else{
				t += r-cnt_0;
			}
		}
		ans = min(ans, t);
	}
	cout<<r*c-ans<<endl;
	return 0;
}

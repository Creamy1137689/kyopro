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
	int H,W,K; cin>>H>>W>>K;
	vector<vector<char>> nap(H, vector<char> (W));
	rep(i,H)rep(j,W)cin>>nap[i][j];
	int ans = 0;
	for(int bith = 0; bith < (1<<H); ++bith){
		for(int bitw = 0; bitw < (1<<W); ++bitw){
			vector<vector<char>> t_nap = nap;
			rep(i,H){
				if(bith & (1<<i)){
					rep(j,W)t_nap[i][j] = 'R';
				}
			}
			rep(j,W){
				if(bitw & (1<<j)){
					rep(i,H)t_nap[i][j] = 'R';
				}
			}
			int e_ans = 0;
			rep(i,H){
				rep(j,W){
					if(t_nap[i][j] == '#')++e_ans;
				}
			}
			if(e_ans == K)++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int H,W,b;
	cin>>W>>H>>b;
	vector<vector<bool>> cont(H+1, vector<bool>(W+1,false));
	rep(i,b){
		int x,y; cin>>x>>y;
		cont[y][x] = true;
	}
	vector<vector<int>> nap(H+1, vector<int> (W+1,0));
	// rep(i,W)if(!cont[0][i])nap[0][i] = 1;
	// rep(i,H)if(!cont[i][0])nap[i][0] = 1;
	nap[0][1] = 1;
	for(int i = 1; i<=H; ++i){
		for(int j = 1; j<=W; ++j){
			bool ok = true;
			rep(k,b){
				if(cont[i][j]){
					ok = false;
				}
			}
			if(ok){
				nap[i][j] = nap[i-1][j] + nap[i][j-1];
			}else{
				nap[i][j] = 0;
			}
		}
	}
	cout<<nap[H][W]<<endl;
	return 0;
}
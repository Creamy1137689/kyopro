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

int d8x[9] = {0,1,1,1,0,-1,-1,-1,0};
int d8y[9] = {1,1,0,-1,-1,-1,0,1,0};

int main(){
	int H,W; cin>>H>>W;
	vector<vector<char>> input(H+2, vector<char>(W+2, '#'));
	vector<vector<char>> ans(H+2, vector<char>(W+2, '.'));
	REP(i,H)REP(j,W)cin>>input[i][j];
	REP(i,H)REP(j,W){
		if(input[i][j] == '#'){
			bool ok = true;
			rep(k, 8){
				if(input[i + d8y[k]][j + d8x[k]] == '.')ok = false;
			}
			if(ok)ans[i][j] = '#';
		}
	}
	bool pos = true;
	REP(i,H){
		REP(j,W){
			if(input[i][j] == '.')continue;
			bool exist = false;
			rep(k,9){
				if(ans[i + d8y[k]][j + d8x[k]] == '#')exist = true;
			}
			if(!exist)pos = false;
		}
	}
	if(!pos){
		cout<<"impossible"<<endl;
		return 0;
	}
	cout<<"possible"<<endl;
	REP(i,H){REP(j,W)cout<<ans[i][j]; cout<<endl;}
	return 0;
}
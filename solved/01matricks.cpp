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
	int H, W, A, B;
	cin>>H>>W>>A>>B;
	vector<vector<int>> ans(H, vector<int> (W,0));
	rep(i,H)rep(j,A)if(i>=B)ans[i][j] = 1;
	rep(j,W)rep(i,B)if(j>=A)ans[i][j] = 1;
	rep(i,H){rep(j,W)cout<<ans[i][j]; cout<<endl;}
	return 0;
}

// int main(){
// 	int H, W, A, B; 
// 	cin>>H>>W>>A>>B;
// 	vector<vector<int>> ans(H, vector<int> (W,0));
// 	bool can = true;
// 	if(B != 0 && B*3 < H)can = false;
// 	if(A != 0 && A*3 < W)can = false;
// 	if(!can){cout<<"No"<<endl; return 0;}
// 	rep(i,H)rep(j,W){
// 		int ok = 1;
// 		if(B != 0)if((i/B)%2 == 1){ok *= -1;}
// 		if(A != 0)if((j/A)%2 == 1){ok *= -1;}
// 		if(ok == 1)ans[i][j] = 1;
// 	}
// 	rep(i,H){rep(j,W)cout<<ans[i][j]; cout<<endl;}
// 	return 0;
// }
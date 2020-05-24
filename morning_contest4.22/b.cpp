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
	int nap[3][3];
	rep(i,3)rep(j,3)cin>>nap[i][j];
	int a2 = nap[0][1]-nap[0][0];
	int a3 = nap[0][2]-nap[0][0];
	int b2 = nap[1][0]-nap[0][0];
	int b3 = nap[2][0]-nap[0][0];
	bool ans = true;
	if(a2+b2 != nap[1][1]-nap[0][0])ans = false;
	if(a3+b2 != nap[1][2]-nap[0][0])ans = false;
	if(a2+b3 != nap[2][1]-nap[0][0])ans = false;
	if(a3+b3 != nap[2][2]-nap[0][0])ans = false;
	cout<<((ans)?"Yes":"No")<<endl;
	return 0;
}
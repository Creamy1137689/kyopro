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

char monitor[5][300];

int check(int s, int t){
	int res = inf;
	if(monitor[1][s+1] == '#')res = 1;
	else if(monitor[4][s] == '#'){
		int digit = 0;
		if(monitor[1][s] == '#')digit += 1;
		if(monitor[1][t] == '#')digit += 10;
		if(monitor[3][s] == '#')digit += 100;
		if(monitor[3][t] == '#')digit += 1000;
		if(monitor[2][s+1] == '#')digit += 10000;
		if(digit == 1111)res = 0;
		else if(digit == 11111)res = 8;
		else if(digit == 11101)res = 6;
		else if(digit == 10110)res = 2;
		else if(digit == 11001)res = 5;
		else if(digit == 11010)res = 3;
		else if(digit == 11011)res = 9;
	}else{
		if(monitor[0][s+1] == '.')res = 4;
		else res = 7;
	}
	return res;
}

int main(){
	int N; cin>>N;
	rep(i,5)rep(j,4*N+1)cin>>monitor[i][j];
	string ans;
	rep(i,N){
		int s = 1 + i*4;
		int t = 3 + i*4;
		// cout<<check(s,t)<<endl;
		char el = check(s,t) + '0';
		ans+=el;
	}
	cout<<ans<<endl;
	return 0;
}
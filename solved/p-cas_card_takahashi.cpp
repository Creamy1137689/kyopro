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
	int x,y,dx,dy;
	string W;
	vector<string> input(9);
	cin>>x>>y>>W;
	--x; --y;
	rep(i,9)cin>>input[i];

	if(W == "R"){dx = 1; dy = 0;}
	if(W == "L"){dx = -1; dy = 0;}
	if(W == "U"){dx = 0; dy = -1;}
	if(W == "D"){dx = 0; dy = 1;}
	if(W == "RU"){dx = 1; dy = -1;}
	if(W == "RD"){dx = 1; dy = 1;}
	if(W == "LU"){dx = -1; dy = -1;}
	if(W == "LD"){dx = -1; dy = 1;}

	rep(i,4){
		cout<<input[y][x];
		if(dx == 1 && x == 8)dx = -1;
		if(dx == -1 && x == 0)dx = 1;
		if(dy == 1 && y == 8)dy = -1;
		if(dy == -1 && y == 0)dy = 1;
		x += dx; y += dy;
	}
	cout<<endl;
	return 0;
}
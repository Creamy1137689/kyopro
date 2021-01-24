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

double dis(int a, int b,int c,int d){
	return sqrt((double)((a-c)*(a-c) + (b-d)*(b-d)));
}

int main(){
	int x1, y1, r, x2, y2, x3, y3;
	cin>>x1>>y1>>r>>x2>>y2>>x3>>y3;
	bool red = false, blue = false;
	for(int x = -100; x<=100; ++x){
		for(int y = -100; y<100; ++y){
			int state = 0;
			if(dis(x,y,x1,y1) <= r)state += 1;
			if(x2 <= x && x <= x3 && y2 <= y && y <= y3)state += 2;
			if(state == 1)red = true;
			if(state == 2)blue = true;
		}
	}
	cout<<((red)?"YES":"NO")<<endl;
	cout<<((blue)?"YES":"NO")<<endl;
	return 0;
}
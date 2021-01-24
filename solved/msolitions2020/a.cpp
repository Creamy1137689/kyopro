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
	int x; cin>>x;
	if(400 <= x && x < 600)cout<<8<<endl;
	if(600 <= x && x < 800)cout<<7<<endl;
	if(800 <= x && x < 1000)cout<<6<<endl;
	if(1000 <= x && x < 1200)cout<<5<<endl;
	if(1200 <= x && x < 1400)cout<<4<<endl;
	if(1400 <= x && x < 1600)cout<<3<<endl;
	if(1600 <= x && x < 1800)cout<<2<<endl;
	if(1800 <= x && x < 2000)cout<<1<<endl;
	return 0;
}
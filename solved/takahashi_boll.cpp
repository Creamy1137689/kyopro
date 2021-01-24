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
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

long double A, B, C;
long double PI = 3.1415926535897932384626433;

bool isOK(long double k){
	if(A * k + B * sin(k * C * PI) >= 100) return true;
	else return false;
}

long double binary_search(long double ok, long double ng){
	rep(_,70){
		long double mid = (ok + ng)/2;
		if(isOK(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	cin >> A >> B >> C;
	cout << fixed << setprecision(10) << binary_search(10000, -0.001) << endl;
	return 0;
}

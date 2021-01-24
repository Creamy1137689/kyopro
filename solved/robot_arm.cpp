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

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int nax = a + b + c;
	int nin;
	if(a + b >= c && b + c >= a && c + a >= b)nin = 0;
	else nin = min({abs(a + b - c), abs(a - b - c), abs(b - a - c)});
	cout << fixed << setprecision(15) << (long double)(nax * nax - nin * nin) * 3.141592653589793238 << endl;
	return 0;
}

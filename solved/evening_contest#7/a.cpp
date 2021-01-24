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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int d;
	vector<int> a(3);
	bool ok = false;
	cin>>a[0]>>a[1]>>a[2]>>d;
	if(abs(a[0]-a[2])<=d)ok = true;
	sort(all(a));
	if(a[2]-a[1]<=d && a[1]-a[0] <= d)ok = true;
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}
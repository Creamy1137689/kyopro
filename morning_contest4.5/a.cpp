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
	string t;
	cin>>t;
	bool w = false, e = false, s = false, n = false;
	rep(i,t.size()){
		if(t[i] == 'W')w = true;
		if(t[i] == 'E')e = true;
		if(t[i] == 'S')s = true;
		if(t[i] == 'N')n = true;
	}
	bool ok = false;
	if(w == e && s == n)ok = true;
	cout<<((ok)?"Yes":"No")<<endl;
	return 0;
}
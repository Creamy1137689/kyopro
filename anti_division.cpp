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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll div_cnt(ll a, ll b, ll div){
	ll ans;
	ans = b/div;
	ll t = (a-1)/div;
	return ans-t;
}

int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll e_by_c = div_cnt(a, b, c);
	ll e_by_d = div_cnt(a, b, d);
	ll e_by_cd = div_cnt(a,b, (c*d)/__gcd(c,d));
	cout<<b-a+1-e_by_c-e_by_d+e_by_cd<<endl;
	return 0;
}
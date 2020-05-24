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

ll lcm(vector<ll> a, int p, ll ans = 1LL){
    if(p>=a.size())return ans;
    ans = a[p]/__gcd(ans, a[p])*ans;
    ans = lcm(a, p+1, ans);
    return ans;
}

int main(){
	int N; cin>>N;
	vector<ll> T(N);
	rep(i,N)cin>>T[i];
	cout<<lcm(T, 0)<<endl;
	return 0;
}
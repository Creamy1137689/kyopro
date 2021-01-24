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

ll rep_power_modM(ll a, ll n, ll M){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

ll comb(ll n, ll r, ll M = MOD){
    ll ans = 1; rep(i,r){ans *= (n-i)%M; ans%=M;}
    ll divisor = 1; rep(i,r){divisor *= (i+1)%MOD; divisor %=M;}
    ans = ans * rep_power_modM(divisor,M-2,M)%M; if(ans<0)ans+=M;
    return ans;
}

int main(){
	int H,W;
	cin>>W>>H;
	cout<<comb(W+H-2,W-1)<<endl;
	return 0;
}
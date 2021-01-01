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
const int MOD = 998244353;

long long modpow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

ll dp[300200] = {};

void init(){
    rep(i,300200)dp[i] = INF;
}

ll calc(int k){
    if(dp[k] != INF){return dp[k];}
    ll res = 0;
    for(int i = 1; i <= k; i += 2){
        if(k - i == i){res += 1;}
        else {res += calc(k-i);}
        res %= MOD;
    }
    res %= MOD;
    return dp[k] = res;
}

ll solve(int N){
    init();
    dp[0] = 1;
    ll ans = calc(N);
    cout << ans << endl;
    ll inv = modpow(2, N);
    inv = modpow(inv, MOD-2); 
    return ans*inv%MOD;
}

int main(){
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}

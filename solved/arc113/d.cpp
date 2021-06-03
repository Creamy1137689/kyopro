#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
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

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> sumb(k+2, 0);
    REP(i,k){
        sumb[i] = modpow(k-i+1, m) - modpow(k-i, m);
        if(sumb[i] < 0)sumb[i] += MOD;
    }
    REP(i,k)sumb[i] = (sumb[i-1] + sumb[i]) % MOD;
    ll ans = 0;
    if(n == 1 && m == 1){
        ans = k;
    }else if(n == 1){
        ans = modpow(k, m);
    }else if(m == 1){
        ans = modpow(k, n);
    }else{
        REP(i,k){
            ll suma = modpow(i, n) - modpow((i-1), n);
            if(suma < 0)suma += MOD;
            ll t = sumb[k]- sumb[i-1];
            if(t < 0)t += MOD;
            ans += suma*t % MOD;
            if(ans < 0)ans += MOD;
            ans %= MOD;
        }
    }
    while(ans < 0)ans += MOD;
    cout << ans << endl;
    return 0;
}

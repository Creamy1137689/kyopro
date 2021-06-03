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
const int MOD = (int)1e9 + 7;

int solve(int a, int b){
    cout << a << b << endl;
    return a + b;
}

int main(){
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int primen = 15;
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n)cin >> x[i];
    ll ans = INF;
    for(int bit = 0; bit < (1 << primen); ++bit){
        ll t = 1;
        rep(i,primen){
            if(bit & (1 << i))t *= primes[i];
        }
        bool ok = true;
        rep(i,n){
            if(gcd(x[i], t) == 1)ok = false;
        }
        if(ok)ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}

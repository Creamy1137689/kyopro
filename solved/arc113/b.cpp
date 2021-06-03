#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
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
typedef boost::multiprecision::cpp_int lint;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = 4;

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
    ll a, b, c;
    cin >> a >> b >> c;
    ll t = modpow(b, c);
    a %= 10;
    cout << (ll)pow(a, t+4) % 10 << endl;
    return 0;
}

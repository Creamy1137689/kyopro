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
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

long double eps = 1e-11;

int main(){
    long double x, y, r;
    cin >> x >> y >> r;
    ll ans = 0;
    int end = y - r;
    for(int h = y + r; h >= end; --h ){
        long double a = r + y - h, b = r - y + h;
        long double d = sqrt(a*b);
        ans += floor(x + d + eps) - floor(x - d-eps);
    }
    cout << ans << endl;
    return 0;
}

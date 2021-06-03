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

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n+1, 0);
    rep(i,n)cin >> a[i];
    rep(i,n)sum[i+1] = sum[i] + a[i];
    ll ans = 0;
    rep(i,n)ans += a[i]*a[i] * (n-1);
    rep(i,n-1)ans -= 2*a[i]*(sum[n] - sum[i+1]);
    cout << ans << endl;
    return 0;
}

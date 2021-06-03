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

int main(){
    ll n, c;
    ll ans = 0;
    cin >> n >> c;
    vector<ll> x(n), revx(n);
    vector<ll> v(n);
    vector<ll> formax(n), revmax(n);
    rep(i,n){
        cin >> x[i] >> v[i];
        revx[i] = c-x[i];
        formax[i] = v[i];
        revmax[i] = v[i];
    }
    rep(i,n-1)formax[i+1] += formax[i];
    rep(i,n)formax[i] -= x[i];
    rep(i,n-1)formax[i+1] = max(formax[i], formax[i+1]);
    for(int i = n-1; i > 0; --i)revmax[i-1] += revmax[i];
    for(int i = n-1; i >= 0; --i)revmax[i] -= revx[i];
    for(int i = n-1; i > 0; --i)revmax[i-1] = max(revmax[i], revmax[i-1]);
    rep(i,n)ans = max({ans, formax[i], revmax[i]});
    ll nv = 0;
    rep(i,n-1){
        nv += v[i];
        ans = max(ans, nv - 2*x[i] + max(0LL, revmax[i + 1]));
    }
    nv = 0;
    for(int i = n-1; i >= 1; --i){
        nv += v[i];
        ans = max(ans, nv - 2*revx[i] + max(0LL, formax[i - 1]));
    }
    cout << ans << endl;
    return 0;
}

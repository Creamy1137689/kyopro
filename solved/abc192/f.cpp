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

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll ans = INF;
    REP(k, n){
        vector<vector<ll>> dp(k+1, vector<ll>(k, -INF));
        dp[0][0] = 0;
        for(auto e:a) for(int i = k-1; i >= 0; --i) for(int j = 0; j < k; ++j){
            if(dp[i][j] != -INF){
                ll v = e + dp[i][j];
                chmax(dp[i+1][v % k], v);
            }
        }
        if(dp[k][x % k] != -INF)chmin(ans, (x - dp[k][x % k]) / k);
    }
    cout << ans << endl;
    return 0;
}

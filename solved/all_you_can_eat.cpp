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

int main(){
    int n, t;
    cin >> n >> t;
    vector<P> dish(n);
    rep(i,n)cin >> dish[i].first >> dish[i].second;
    sort(all(dish));
    vector<vector<int>> dp(t+1, vector<int>(n+1, 0));
    rep(i,t){
        rep(j,n){
            int ni = min(t, i + dish[j].first);
            chmax(dp[i][j+1], dp[i][j]);
            chmax(dp[ni][j+1], dp[i][j] + dish[j].second);
        }
    }
    rep(i,n)chmax(dp[t][i+1], dp[t][i]);
    cout << dp[t][n] << endl;
    return 0;
}

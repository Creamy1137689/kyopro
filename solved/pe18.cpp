#include <bits/stdc++.h>
using namespace std;

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
    int n;
    cin >> n ;
    vector<vector<int>> in(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    rep(i,n)rep(j,i+1)cin >> in[i][j];
    dp[0][0] = in[0][0];
    REP(i,n-1){
        rep(j, i+1){
            if(j < i)chmax(dp[i][j], dp[i-1][j] + in[i][j]);
            if(j != 0)chmax(dp[i][j], dp[i-1][j-1] + in[i][j]);
        }
    }
    int ans = 0;
    rep(i,n)chmax(ans, dp[n-1][i]);
    cout << ans << endl;
    return 0;
}

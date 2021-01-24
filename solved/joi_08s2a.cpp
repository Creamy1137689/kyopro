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
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int N, D;
    cin >> N >> D;
    int cost[D][N];
    int dp[D+1][N][3];
    int mins[D+1];
    rep(i,D)rep(j,N)cin >> cost[i][j];
    rep(i,D+1)rep(j,N)rep(k,3)dp[i][j][k] = inf;
    rep(i,D+1)mins[i] = inf;
    mins[0] = 0;
    rep(i,D)rep(j,N)rep(k,3){
        int ni = i + 1, nj = j, nk = min(k + 1, 2);
        if(k == 0)chmin(dp[ni][nj][nk], mins[i] + cost[i][j]);
        if(k == 1)chmin(dp[ni][nj][nk], dp[i][j][k] + cost[i][j] * 9 / 10);
        if(k == 2)chmin(dp[ni][nj][nk], dp[i][j][k] + cost[i][j] * 7 / 10);
        chmin(mins[ni], dp[ni][nj][nk]);
    }
    int ans = inf;
    rep(j,N)rep(k,3)chmin(ans, dp[D][j][k]);
    cout << ans << endl;
}

//int main(){
//    int N, D;
//    cin >> N >> D;
//    vector<vector<ll>> cost(D, vector<ll>(N));
//    vector<vector<ll>> dp(D+1, vector<ll>(N, INF));
//    vector<ll> mins(D+1, INF);
//    rep(i,D)rep(j,N)cin >> cost[i][j];
//    rep(i,N)dp[0][i] = 0;
//    mins[0] = 0;
//    rep(i,D)rep(j,N){
//        chmin(dp[i+1][j], mins[i] + cost[i][j]);
//        if(i > 0)chmin(dp[i+1][j], (ll)(dp[i][j] + (double)cost[i][j]*0.9));
//        if(i > 1)chmin(dp[i+1][j], (ll)(dp[i-1][j] + (double)cost[i-1][j]*0.9 + (double)cost[i][j]*0.7));
//        chmin(mins[i+1], dp[i+1][j]);
//    }
//    rep(i,D+1){rep(j,N)cout << dp[i][j] << ' '; cout << endl;}
//    ll ans = INF;
//    rep(i,N)chmin(ans, dp[D][i]);
//    cout << ans << endl;
//    return 0;
//}

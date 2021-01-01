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
const int MOD = (int)1e5;

void add(ll &k, ll x){
    k += x; k %= MOD;
    return ;
}

int main(){
    int h,w;
    cin >> w >> h;
    // dp[i][j][0] from below over 2
    // dp[i][j][1] from left  over 2
    // dp[i][j][2] from below 1
    // dp[i][j][3] from left 1
    ll dp[110][110][4];
    rep(i,110)rep(j,110)rep(k,4)dp[i][j][k] = 0;
    dp[1][0][0] = 1; dp[0][1][1] = 1;  
    rep(i,h)rep(j,w){
        add(dp[i+1][j][0], dp[i][j][0]);
        add(dp[i][j+1][3], dp[i][j][0]);

        add(dp[i+1][j][2], dp[i][j][1]);
        add(dp[i][j+1][1], dp[i][j][1]);

        add(dp[i+1][j][0], dp[i][j][2]);
        add(dp[i][j+1][1], dp[i][j][3]);
    }
    ll ans = dp[h-1][w-1][0] + dp[h-1][w-1][1] + dp[h-1][w-1][2] + dp[h-1][w-1][3];
    ans %= MOD;
    cout << ans << endl;
    return 0;
}

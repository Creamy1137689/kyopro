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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n;
    int nap[21][21];
    cin >> n;
    rep(i,n)rep(j,n)cin >> nap[i][j];
    vector<ll> dp(1 << n, 0);
    dp[0] = 1;
    REP(j, 1 << n){
        int i = __builtin_popcount(j);
        rep(k,n){
            if(nap[i-1][k] == 1 && j & (1 << k)){
                dp[j] = (dp[j] + dp[j & (~(1 << k))]) % MOD;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}

/* int main(){ */
/*     int n; */
/*     int nap[21][21]; */
/*     cin >> n; */
/*     rep(i,n)rep(j,n)cin >> nap[i][j]; */
/*     vector<vector<ll>> dp(n+1, vector<ll>((1 << n) + 1, 0)); */
/*     dp[0][0] = 1; */
/*     REP(i,n){ */
/*         rep(j, (1 << n)){ */
/*             rep(k, n){ */
/*                 if(nap[i-1][k] == 1 && j & (1 << k)){ */
/*                     dp[i][j] += dp[i-1][j & (~(1 << k))]; */
/*                     dp[i][j] %= MOD; */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     /1* rep(i,n+1){rep(j,(1 << n))cout << dp[i][j] << ' ';cout << endl;} *1/ */
/*     cout << dp[n][(1 << n)-1] << endl; */
/*     return 0; */
/* } */

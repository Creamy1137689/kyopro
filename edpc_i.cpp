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
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int N;
    cin >> N;
    vector<double> coin(N);
    rep(i,N)cin >> coin[i];
    vector<vector<double>> dp(N+1, vector<double>(3010, 0));
    dp[0][0] = 1;
    rep(i,N){
        rep(j,3010){
            dp[i+1][j+1] += dp[i][j] * coin[i];
            dp[i+1][j] += dp[i][j] * (1-coin[i]);
        }
    }
    double ans = 0;
    rep(i,3010)if(N-i > i)ans += dp[N][N-i];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

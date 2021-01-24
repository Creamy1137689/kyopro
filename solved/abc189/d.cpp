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
    cin >> n;
    vector<string> ss(n);
    rep(i,n)cin >> ss[i];
    vector<vector<ll>> dp(80, vector<ll>(2,0));
    dp[0][1] = 1; dp[0][0] = 1;
    rep(i,n){
        if(ss[i] == "AND"){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][0] + dp[i][1]*2;
        }else{
            dp[i+1][0] = dp[i][0]*2 + dp[i][1];
            dp[i+1][1] = dp[i][1];
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}

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
    int s;
    cin >> s;
    vector<ll> dp(s*3, 1);
    dp[0] = 0; dp[1] = 0; dp[2] = 0;
    for(int i = 3; i < s; ++i){
        for(int x = 3; x < s; ++x){
            dp[i+x] = (dp[i+x] + dp[i]) % MOD;
        }
    }
    cout << dp[s] << endl;
    return 0;
}

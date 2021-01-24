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

int dp[510][30000] = {};

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int N, M;
    cin >> M >> N;
    vector<int> p(M);
    vector<int> cap(N);
    vector<int> cost(N);
    rep(i,M)cin >> p[i];
    rep(i,N)cin >> cap[i] >> cost[i];
    sort(all(p), greater<int>());
    rep(i,510)rep(j,30000)dp[i][j] = inf;
    dp[0][0] = 0;
    REP(i,N){
        rep(j,30000){
            chmin(dp[i][j], dp[i-1][j]);
            if(j - cap[i-1] >= 0){
                chmin(dp[i][j], dp[i-1][j-cap[i-1]] + cost[i-1]);
            }
        }
    }
    int ans = 0;
    int value_sum = 0;
    rep(i,29999){
        if(i < M)value_sum += p[i];
        ans = max(ans, value_sum - dp[N][i+1]);
    }
    cout << ans << endl;
    return 0;
}

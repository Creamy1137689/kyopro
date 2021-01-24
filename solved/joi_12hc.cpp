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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int dp[3030][3030] = {};

int main(){
    int N, T, S;
    cin >> N >> T >> S;
    vector<int> hap(N);
    vector<int> time(N);
    rep(i,N)cin >> hap[i] >> time[i];
    REP(i,N){
        REP(t,T){
            chmax(dp[i][t], dp[i-1][t]);
            int back_time = t - time[i-1];
            if(back_time >= 0 && !(back_time < S && S < t)){
                chmax(dp[i][t], dp[i-1][back_time] + hap[i-1]);
            }
        }
    }
    int ans = 0;
    REP(i,T)chmax(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}

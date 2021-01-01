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

int main(){
    ll N, D, K;
    cin >> N >> D >> K;
    vector<LP> ev(N);
    vector<ll> times(N);
    rep(i,N)cin >> ev[i].second >> ev[i].first;
    rep(i,N)times[i] = ev[i].first;
    sort(all(ev));
    sort(all(times));
    vector<vector<bool>> dp(N+1, vector<bool>(N+1, false));
    rep(i,N){
        if(ev[i].second == 1)dp[0][i] =true;
        else {
            if(ev[i].first <= D)dp[0][i] = true;
        }
    }
    rep(al,N){
        rep(en, N){
            if(!dp[al][en])continue;
            rep(to, N){
                if(en == to)continue;
                int cost = D;
                if(ev[en].second == ev[to].second && ev[en].first < ev[to].first){
                    dp[al+1][to] = true;
                }else{
                    if(ev[en].first + cost + 1 <= ev[to].first){
                        dp[al+1][to] = true;
                    }
                }
            }
        }
    }
    //rep(i,N){rep(j,N)cout << dp[i][j] << ' ';cout << endl;}
    int ans = 0;
    rep(i,N)rep(j,N){
        if(dp[i][j])ans = max(ans, i+1);
    }
    cout << ans << endl;
    return 0;
}

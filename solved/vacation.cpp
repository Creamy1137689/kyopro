#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

//aとbのうち大きい値をaとして採用する
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int main(){
    int N_MAX = 110000;
    int n; cin>>n;
    vector<int>a(N_MAX);
    vector<int>b(N_MAX);
    vector<int>c(N_MAX);
    rep(i,n)cin>>a[i]>>b[i]>>c[i];
    vector <vector<ll>> dp(N_MAX,vector<ll>(3,0));

    rep(i,n){
        chmax(dp[i+1][0],dp[i][1]+a[i]);
        chmax(dp[i+1][0],dp[i][2]+a[i]);
        chmax(dp[i+1][1],dp[i][0]+b[i]);
        chmax(dp[i+1][1],dp[i][2]+b[i]);
        chmax(dp[i+1][2],dp[i][0]+c[i]);
        chmax(dp[i+1][2],dp[i][1]+c[i]);
    }

    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;return 0;
}

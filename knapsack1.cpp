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
    int N,W; cin>>N>>W;
    vector<int> w(N);
    vector<int> v(N);
    rep(i,N)cin>>w[i]>>v[i];

    vector<vector<ll>> dp(N+1,vector<ll> (W+1,0));

    //rep(i,N+1){rep(j,W+1)cout<<dp[i][j]<<' '; cout<<endl;}

    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=W; j++){
            chmax(dp[i][j], dp[i-1][j]);
            if(w[i-1]<= j) chmax(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
        }
    }
    //cout<<"----------"<<endl;
    //rep(i,N+1){rep(j,W+1)cout<<dp[i][j]<<' '; cout<<endl;}
    cout<<dp[N][W]<<endl;return 0;
}

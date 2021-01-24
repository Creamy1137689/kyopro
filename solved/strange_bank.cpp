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

//aとbのうち小さい値をaとして採用する
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int N_MAX = 1000000;
    int n; cin>>n;

    set<int> money;
    money.insert(1);
    int six= 6;
    while(six<=n){
        money.insert(six);
        six*=6;
    }
    int nine = 9;
    while(nine<=n){
        money.insert(nine);
        nine*=9;
    }

    vector<int> dp(N_MAX,inf);
    dp[0] = 0;
    rep(i,n){
        for(auto x:money){
            chmin(dp[i+x], dp[i]+1);
        }
    }

    cout<<dp[n]<<endl;return 0;
}

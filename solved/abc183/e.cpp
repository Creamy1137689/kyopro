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

int H, W;
char nap[2020][2020];
ll memo[2020][2020];
ll sum_tate[2020][2020];
ll sum_yoko[2020][2020];
ll sum_naname[2020][2020];

ll solve(int i, int j){
    if(memo[i][j] != -1) return memo[i][j];
    if(i == H && j == W) return 1;
    ll res = 0;
    if(i < H && nap[i+1][j] == '.'){
        ll tate = solve(i+1, j);
        sum_tate[i][j] = sum_tate[i+1][j] + tate;
        sum_tate[i][j] %= MOD;
    }
    if(j < W && nap[i][j+1] == '.'){
        ll yoko = solve(i, j + 1);
        sum_yoko[i][j] = sum_yoko[i][j+1] + yoko;
        sum_yoko[i][j] %= MOD;
    }
    if(i < H && j < W && nap[i+1][j+1] == '.'){
        ll naname = solve(i + 1, j + 1);
        sum_naname[i][j] = sum_naname[i+1][j+1] + naname;
        sum_naname[i][j] %= MOD;
    }
    return memo[i][j] = (sum_yoko[i][j] + sum_tate[i][j] + sum_naname[i][j]) % MOD;
}

int main(){
    cin >> H >> W;
    REP(i,H)REP(j,W)cin >> nap[i][j];
    rep(i,2020)rep(j,2020)memo[i][j] = -1, sum_naname[i][j] = 0, sum_tate[i][j] = 0, sum_yoko[i][j] = 0;
    cout << solve(1,1) << endl;
    //REP(i,H){REP(j,W)cout << memo[i][j] << ' '; cout << endl;}
    return 0;
}

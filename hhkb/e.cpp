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
#include <atcoder/all>
using namespace atcoder;
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

long long pows(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> nap(H+1, vector<char>(W+1, '#'));
    vector<vector<int>> yoko(H, vector<int>(W,0));
    vector<vector<int>> tate(H, vector<int>(W,0));
    ll k = 0;
    rep(i,H)rep(j,W){
        cin >> nap[i][j];
        if(nap[i][j] == '.')++k;
    }
    //yoko
    for(int i = 0; i < H; ++i){
        int cnt = 0;
        vector<int> num_cnt(W, 0);
        for(int j = 0; j < W; ++j){
            if(nap[i][j] == '#')++cnt;
            if(nap[i][j] == '.')num_cnt[cnt]++;
            yoko[i][j] = cnt;
        }
        for(int j = 0; j < W; ++j){
            yoko[i][j] = num_cnt[yoko[i][j]];
        }
    }
    //tate
    for(int j = 0; j < W; ++j){
        int cnt = 0;
        vector<int> num_cnt(H, 0);
        for(int i = 0; i < H; i++){
            if(nap[i][j] == '#')++cnt;
            if(nap[i][j] == '.')num_cnt[cnt]++;
            tate[i][j] = cnt;
        }
        for(int i = 0; i < H; ++i){
            tate[i][j] = num_cnt[tate[i][j]];
        }
    }
    ll ans = 0;
    //vector<ll> tmp(4500000);
    //tmp[0] = 1;
    //REP(i,4499999){tmp[i] = tmp[i-1] * 2;tmp[i] %=MOD;}
    rep(i,H)rep(j,W){
        if(nap[i][j] == '#')continue;
        ll m = yoko[i][j] + tate[i][j] - 1; // 注意
        ll other = k - m;
        //ans += (tmp[m]-1LL)%MOD * tmp[other];
        //ans += (pow_mod(2, m, MOD)-1LL) * pow_mod(2, other, MOD);
        ans += (pows(2, m)-1LL) * pows(2, other);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

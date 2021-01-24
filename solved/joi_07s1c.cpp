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
const ll inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int H, W, a, b;
    cin >> W >> H >> a >> b;
    vector<vector<ll>> nap(1010, vector<ll>(1010));
    vector<vector<ll>> sum(1010, vector<ll>(1010,0));
    rep(i,H)rep(j,W){
        scanf("%lld", &nap[i][j]);
        if(nap[i][j] == -1)nap[i][j] = inf*10;
    }
    REP(i,H)REP(j,W){
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + nap[i-1][j-1];
    }
    ll ans = INF, t;
    for(int i = 0; i + b <= H; ++i){
        for(int j = 0; j + a <= W; ++j){
            t = sum[i+b][j+a] + sum[i][j] - sum[i+b][j] - sum[i][j+a];
            ans = min(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}

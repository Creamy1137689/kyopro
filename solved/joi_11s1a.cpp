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

int lack(int a, int b){
    if((a == 0 && b == 1) || (a == 1 && b == 0))return 2;
    if((a == 1 && b == 2) || (a == 2 && b == 1))return 0;
    if((a == 0 && b == 2) || (a == 2 && b == 0))return 1;
    return -1;
}

int main(){
    ll H, W;
    cin >> H >> W;
    int nap[H][W];
    rep(i,H)rep(j,W)cin >> nap[i][j];
    ll ans = H*(H-1)*W*(W-1)/4;
    ll same_count[W][W];
    ll wg_count[W][W];
    ll wb_count[W][W];
    ll gb_count[W][W];
    rep(j,W)rep(p,W){
        same_count[j][p] = 0;
        wg_count[j][p] = 0;
        wb_count[j][p] = 0;
        gb_count[j][p] = 0;
    }
    rep(i,H)rep(j,W){
        for(int p = j + 1; p < W; ++p){
            if(nap[i][j] == nap[i][p])same_count[j][p]++;
            int sw = lack(nap[i][j], nap[i][p]);
            if(sw == 0)wg_count[j][p]++;
            if(sw == 1)wb_count[j][p]++;
            if(sw == 2)gb_count[j][p]++;
        }
    }
    //rep(j,W)for(int p = j+1; p < W; ++p){
    //    printf("[j,p = %d, %d] -> [same:%d, w&g:%d, w&b:%d, b&g:%d]\n", j, p, same_count[make_pair(j,p)], wg_count[make_pair(j,p)], wb_count[make_pair(j,p)], gb_count[make_pair(j,p)]);
    //}
    ll exs = 0;
    rep(i,H)rep(j,W){
        for(int p = j + 1; p < W; ++p){
            if(nap[i][j] == nap[i][p]){
                exs += same_count[j][p]-1;
                if(nap[i][j] == 0){
                    exs += wb_count[j][p]*2;
                    exs += gb_count[j][p]*2;
                }
                if(nap[i][j] == 1){
                    exs += wg_count[j][p]*2;
                    exs += gb_count[j][p]*2;
                }
                if(nap[i][j] == 2){
                    exs += wb_count[j][p]*2;
                    exs += wg_count[j][p]*2;
                }
            }
            int sw = lack(nap[i][j], nap[i][p]);
            if(sw == 0)exs += wg_count[j][p]-1;
            if(sw == 1)exs += wb_count[j][p]-1;
            if(sw == 2)exs += gb_count[j][p]-1;
        }
    }
    cout << ans - exs/2 << endl;
    return 0;
}

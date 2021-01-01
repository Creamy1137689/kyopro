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
using namespace std;
using namespace atcoder;

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

int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};
bool nap[1515][1515] = {};

int main(){
    int H, W, N, M, c, d;
    cin >> H >> W >> N >> M;
    vector<P> li(N);
    rep(i,N)cin >> li[i].first >> li[i].second;
    rep(i,N)li[i].first--, li[i].second--;
    rep(i,H)rep(j,W)nap[i][j] = true;
    rep(i,M){
        cin >> c >> d;
        --c; --d;
        nap[c][d] = false;
    }
    //rep(i,H){rep(j,W)cout << nap[i][j]; cout << endl;}
    vector<dsu> yoko(1515), tate(1515);
    rep(i,1515)yoko[i] = dsu(1515);
    rep(i,1515)tate[i] = dsu(1515);
    rep(i,H)rep(j,W){
        if(!nap[i][j])continue;
        rep(k,4){
            int ny = i + d4y[k], nx = j + d4x[k];
            if(ny < 0 || nx < 0 || nx >= W || ny >= H)continue;
            if(nap[ny][nx]){
                if(ny == i){
                    yoko[i].merge(j,nx);
                }else{
                    tate[j].merge(i,ny);
                }
            }
        }
    }
    //rep(i,H){
    //    rep(j,W)printf("[%d,%d] ", tate[j].leader(i), yoko[i].leader(j));
    //    cout << endl;
    //}
    vector<vector<bool>> flyoko(1515, vector<bool>(1515, false));
    vector<vector<bool>> fltate(1515, vector<bool>(1515, false));
    rep(i,N){
        int y = li[i].first, x = li[i].second;
        int ly = tate[x].leader(y);
        int lx = yoko[y].leader(x);
        flyoko[y][lx] = true;
        fltate[ly][x] = true;
    }
    //rep(i,H){rep(j,W)cout << flyoko[i][j];cout << endl;}
    //rep(i,H){rep(j,W)cout << fltate[i][j];cout << endl;}
    int ans = 0;
    rep(i,H)rep(j,W){
        int ly = tate[j].leader(i);
        int lx = yoko[i].leader(j);
        if(fltate[ly][j] || flyoko[i][lx]){
            ++ans;
        };
    }
    //rep(i,H){
    //    rep(j,W){
    //        int ly = tate[j].leader(i);
    //        int lx = yoko[i].leader(j);
    //        printf("%d", (int)fl[i][lx]);
    //    }
    //    cout << endl;
    //}
    cout << ans << endl;
    return 0;
}

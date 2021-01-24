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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int op(int a, int b){return a + b;}
int e(){return 0;}

int main(){
    ll h, w, m;
    cin >> h >> w >> m;
    vector<P> bl(m);
    vector<int> tp(h, inf);
    vector<int> chpos(w, h+1);
    vector<vector<int>> blpos(w, vector<int>());
    int bs = inf;
    int bw = inf;
    rep(i,m){
        int x, y;
        cin >> x >> y;
        --x; --y;
        bl[i] = make_pair(x, y);
        tp[x] = min(tp[x], y);
        chpos[y] = min(chpos[y], x);
        if(y == 0)bs = min(bs, x);
        if(x == 0)bw = min(bw, y);
    }
    segtree<int, op, e> seg(h);
    for(int i = bs; i < h; ++i)tp[i] = 0;
    for(int i = bw; i < w; ++i)chpos[i] = 0;
    rep(i, h){
        if(tp[i] != inf){
            seg.set(i, 1);
            blpos[tp[i]].push_back(i);
        }
    }
    ll ans = w*h;
    for(int i = w-1; i >= 0; --i){
        if(chpos[i] != h+1)ans -= seg.prod(chpos[i], h);
        for(auto t:blpos[i])seg.set(t, 0);
    }
    cout << ans << endl;
    return 0;
}

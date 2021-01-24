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

int N, W, H;

struct cirinfo{
    LP c;
    LP th;
    ll r;
};

ll dist(LP a, LP b){return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);}

bool is_exist(LP d, ll dist){
    bool wl = false, wr = false, hu = false, hd = false;
    if(d.second * d.second >= dist)hd = true;
    if(d.first * d.first >= dist)wl = true;
    if((H-d.second) * (H-d.second) >= dist)hu = true;
    if((W-d.first) * (W-d.first) >= dist)wr = true;
    return (wl && wr && hu && hd);
}

int main(){
    cin >> N >> W >> H;
    vector<LP> dots(N);
    rep(i,N)cin >> dots[i].first >> dots[i].second;
    vector<cirinfo> cir; // first -> center, second -> radius
    rep(i,N){
        for(int j = i + 1; j < N; ++j){
            ll dij = dist(dots[i], dots[j]);
            if(is_exist(dots[i], dij))cir.push_back(cirinfo{dots[i], dots[j], dij});
            if(is_exist(dots[j], dij))cir.push_back(cirinfo{dots[j], dots[i], dij});
        }
    }
    //for(auto x: cir)printf("c(%lld, %lld), A(%lld, %lld), r = %lld\n", x.c.first, x.c.second, x.th.first, x.th.second, x.r);
    int ans = 0;
    rep(i,cir.size()){
        for(int j = i + 1; j < cir.size(); ++j){
            cirinfo c1 = cir[i], c2 = cir[j];
            if(c1.c == c2.c || c1.c == c2.th || c1.th == c2.c || c1.th == c2.th)continue;
            ll d = dist(c1.c, c2.c);
            if(c1.r < c2.r)swap(c1, c2);
            if(4*d*c2.r < (c1.r - c2.r - d)*(c1.r - c2.r - d) && (c1.r - c2.r - d) > 0){
                //cout << line << endl;
                //printf("c1.c = [%lld, %lld], c1.th = [%lld, %lld]\n", c1.c.first, c1.c.second, c1.th.first, c1.th.second);
                //printf("c2.c = [%lld, %lld], c2.th = [%lld, %lld]\n", c2.c.first, c2.c.second, c2.th.first, c2.th.second);
                //cout << line << endl;
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

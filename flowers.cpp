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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll op(ll a, ll b){return max(a, b);}
ll e(){return 0;}

int main(){
    int n;
    cin >> n;
    vector<ll> h(n), a(n), heights(n);
    rep(i,n)cin >> h[i];
    rep(i,n)cin >> a[i];
    segtree<ll, op, e> seg(n);
    heights = h;
    sort(all(heights));
    rep(i,n){
        int ub = upper_bound(all(heights), h[i]) - heights.begin();
        ll now = a[i] + seg.prod(0, ub);
        seg.set(ub-1, now);
    }
    cout << seg.all_prod() << endl;
    return 0;
}

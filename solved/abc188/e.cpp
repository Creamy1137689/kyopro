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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n, m;
    int x, y;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<int>> G(n, vector<int>());
    rep(i,m){
        cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
    }
    vector<ll> mins(n, INF);
    rep(i,n){
        for(auto x:G[i]){
            mins[x] = min({mins[x], mins[i], a[i]});
        }
    }
    ll ans = -INF;
    rep(i,n)ans = max(ans, a[i] - mins[i]);
    cout << ans << endl;
    return 0;
}

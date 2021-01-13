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

int main(){
    ll n, c;
    cin >> n >> c;
    vector<lp> sche;
    map<ll, ll> dat;
    rep(i,n){
        ll a, b, cost;
        cin >> a >> b >> cost;
        dat[a] += cost;
        dat[b+1] -= cost;
    }
    for(auto x:dat){
        sche.push_back(make_pair(x.first, x.second));
    }
    ll ans = 0;
    ll nc = sche[0].second;
    rep(i, sche.size()-1){
        ans += min(nc, c) * (sche[i+1].first - sche[i].first);
        nc += sche[i+1].second;
    }
    cout << ans << endl;
    return 0;
}

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

void solve(){
    int n, k, t;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n)cin >> v[i];
    sort(all(v), greater<ll>());
    ll ans = 0;
    rep(i,k+1)ans += v[i];
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    rep(i,t)solve();
    return 0;
}

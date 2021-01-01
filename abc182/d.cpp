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

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> sum(N+1, 0);
    vector<ll> nax(N+1, 0);
    rep(i,N)cin >> a[i];
    rep(i,N)sum[i+1] = sum[i] + a[i];
    rep(i,N)nax[i+1] = max(sum[i+1], nax[i]);
    ll ans = 0;
    ll now = 0;
    REP(i,N){
        ll nnow = now + sum[i];
        ans = max({ans, nnow, now + nax[i]});
        now = nnow;
    }
    cout << ans << endl;
    return 0;
}

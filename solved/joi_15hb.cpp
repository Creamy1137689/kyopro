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

int N;
vector<ll> a(5000);
ll dp[5000][5000];

ll check(ll l, ll r){
    ll res = max(-INF, dp[l][r]);
    if(l >= N)res = max(res, dp[l - N][r - N]);
    if(r <  N)res = max(res, dp[l + N][r + N]);
    return res;
}

ll dfs(ll l, ll r){
    if(l == r)return a[l];
    if(l > r)return 0;
    ll ch = check(l, r);
    if(ch != -INF){
        if(l >= N)l -= N, r -= N;
        if(r < N){ dp[l][r] = ch; dp[l+N][r+N] = ch; return ch;}
        else return ch;
    }
    ll res = -INF;
    {
        ll nl = l, nr = r;
        ll r1 = a[nl++];
        if(a[nl] >= a[nr])++nl;
        else --nr;
        r1 += dfs(nl, nr);
        res = max(res, r1);
    }
    {
        ll nl = l, nr = r;
        ll r2 = a[nr--];
        if(a[nl] >= a[nr])++nl;
        else --nr;
        r2 += dfs(nl, nr);
        res = max(res, r2);
    }
    return dp[l][r] = res;
}

int main(){
    cin >> N;
    rep(i,N)cin >> a[i], a[i+N] = a[i];
    rep(i,5000)rep(j,5000)dp[i][j] = -INF;
    ll ans = -INF;
    rep(i,N){
        ans = max(ans, dfs(i, i + N - 1));
    }
    cout << ans << endl;
    return 0;
}

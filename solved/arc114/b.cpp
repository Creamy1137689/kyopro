#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = 998244353;

long long modpow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

set<int> ans;
vector<int> vis(200100, -1);
vector<int> f(200100);

void dfs(int v, int id){
    if(vis[f[v]] == id){
        ans.insert(id);
    }else if(vis[f[v]] == -1){
        vis[f[v]] = id;
        dfs(f[v], id);
    }
}

int main(){
    int n;
    cin >> n;
    rep(i,n){cin >> f[i]; --f[i];}
    int id = 0;
    rep(i,n){
        if(vis[i] == -1){
            vis[i] = id;
            dfs(i, id);
            ++id;
        }
    }
    ll res = modpow(2, ans.size());
    --res;
    if(res < 0)res += MOD;
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
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
    vector<vector<int>> g(20, vector<int>(20));
    rep(i,20)rep(j,20){
        cin >> g[i][j];
    }
    ll ans = 0;
    rep(i,20)rep(j,20){
        ll t1 = 1, t2 = 1, t3 = 1, t4 = 1;
        rep(k, 4){
           if(i < 17 && j < 17) t1 *= g[i+k][j+k];
           if(j < 17)t2 *= g[i][j+k];
           if(i < 17)t3 *= g[i+k][j];
           if(i >= 3 && j < 17) t4 *= g[i-k][j+k];
        }
        ans = max({ans, t1, t2, t3, t4});
    }
    cout << ans << endl;
    return 0;
}

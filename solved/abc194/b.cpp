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
const int MOD = (int)1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<P> job(n);
    rep(i,n)cin >> job[i].first >> job[i].second;
    int ans = inf;
    rep(i,n)rep(j,n){
        if(i == j)ans = min(ans, job[i].first + job[j].second);
        else ans = min(ans, max(job[i].first, job[j].second));
    }
    cout << ans << endl;
    return 0;
}

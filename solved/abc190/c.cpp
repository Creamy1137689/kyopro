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
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<P> od(m);
    rep(i,m)cin >> od[i].first >> od[i].second;
    cin >> k;
    vector<P> bal(k);
    rep(i,k)cin >> bal[i].first >> bal[i].second;
    int ans = 0;
    rep(bit, (1<<k)){
        set<int> st;
        rep(i,k){
            if(bit & (1 << i))st.insert(bal[i].first);
            else st.insert(bal[i].second);
        }
        int sc = 0;
        rep(i,m){
            if(st.count(od[i].first) > 0 && st.count(od[i].second) > 0)++sc;
        }
        ans = max(ans, sc);
    }
    cout << ans << endl;
    return 0;
}

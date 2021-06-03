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
    int n, m;
    cin >> n >> m;
    vector<P> st(n), ch(m);
    rep(i,n)cin >> st[i].first >> st[i].second;
    rep(i,m)cin >> ch[i].first >> ch[i].second;
    vector<int> ans(n);
    rep(i,n){
        int pos = -1;
        int dist = inf;
        rep(j,m){
            int d = abs(st[i].first - ch[j].first) + abs(st[i].second - ch[j].second);
            if(dist > d){pos = j+1; dist = d;}
        }
        ans[i] = pos;
    }
    show(ans);
    return 0;
}

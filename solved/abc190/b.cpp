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
    int n, s, d;
    cin >> n >> s >> d;
    vector<int> x(n), y(n);
    rep(i,n)cin >> x[i] >> y[i];
    bool ok = false;
    rep(i,n){
        if(x[i] < s && y[i] > d)ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;    return 0;
}

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
    int n;
    cin >> n;
    vector<int> t(n+1, 0), x(n+1, 0), y(n+1, 0);
    REP(i,n)cin >> t[i] >> x[i] >> y[i];
    bool ok = true;
    REP(i,n){
        int ti = t[i] - t[i-1];
        int dist = abs(x[i]- x[i-1]) + abs(y[i] - y[i-1]);
        if(ti < dist)ok = false;
        if(ti >= dist && ti % 2 != dist % 2)ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

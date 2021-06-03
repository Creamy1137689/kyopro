#include <bits/stdc++.h>
using namespace std;

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

long double solve(){
    int n;
    ll x, y, dist;
    cin >> n;
    vector<long double> er, d;
    rep(i,2*n){
        cin >> x >> y;
        dist = x*x + y*y;
        if(x == 0)d.emplace_back(dist);
        else er.emplace_back(dist);
    }
    sort(all(er)); sort(all(d));
    long double ans = 0;
    rep(i,n){
        ans += sqrt((er[i] + d[i]));
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        cout << fixed << setprecision(15) << solve() << endl;
    }
    return 0;
}

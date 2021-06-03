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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    bool odd = false, even = false;
    rep(i,n){
        cin >> a[i];
        a[i] /= 2;
        if(a[i] % 2 == 0)even = true;
        else odd = true;
    }
    if(odd && even){
        cout << 0 << endl; return 0;
    }else if(even){
        ll g = a[0];
        rep(i,n)g = gcd(g, a[i]);
        rep(i,n){
            a[i] /= g;
            if(a[i] % 2 == 0){
                cout << 0 << endl; return 0;
            }
        }
        m /= g;
    }
    ll l = a[0];
    rep(i,n)l = lcm(l, a[i]);
    if(l > m){
        cout << 0 << endl;
    }else{
        cout << ((m / l - (m/l % 2 == 0)) - 1) / 2 + 1<< endl;
    }
    return 0;
}

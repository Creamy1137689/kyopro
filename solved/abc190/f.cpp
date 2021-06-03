#include <atcoder/fenwicktree.hpp>
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    fenwick_tree<ll> bit(n+2);
    ll sum = 0;
    rep(i,n){
        sum += bit.sum(a[i], n+2);
        bit.add(a[i], 1);
    }
    cout << sum << endl;
    rep(i,n-1){
        sum -= a[i];
        sum += n-a[i]-1;
        cout << sum << endl;
    }
    return 0;
}

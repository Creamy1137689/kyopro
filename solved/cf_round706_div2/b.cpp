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

ll solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    set<ll> st;
    rep(i,n){cin >> a[i]; st.insert(a[i]);}

    if(k == 0)return n;

    sort(all(a));
    ll mex = inf;
    ll nax = a[n-1];
    rep(i,n)if(a[i] != i)mex = min(mex, (ll)i);
    if(mex == inf)return n + k;
    else {
        ll ad = ceil(double(mex + nax) / 2);
        if(st.count(ad) == 0)return n + 1;
        else return n;
    }
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        cout << solve() << endl;
    }
    return 0;
}

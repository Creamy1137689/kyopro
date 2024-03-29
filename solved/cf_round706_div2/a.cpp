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

string solve(){
    string s;
    int n, k;
    cin >> n >> k >> s;
    if(k*2 + 1 > n)return "NO";
    bool ok = true;
    rep(i,k){
        if(s[i] != s[n-1-i])ok = false;
    }
    return (ok ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        cout << solve() << endl;
    }
    return 0;
}

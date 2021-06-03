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
    string s, x;
    cin >> n >> s >> x;
    reverse(all(s));
    reverse(all(x));
    vector<set<int>> dp(n+1, set<int>());
    dp[0].insert(0);
    rep(i,n){
        rep(r, 7){
            int a = 10*r % 7;
            int b = (10*r + s[i]-'0') % 7;
            if(x[i] == 'A'){
                if(dp[i].count(a) == 1 && dp[i].count(b) == 1)dp[i+1].insert(r);
            }else{
                if(dp[i].count(a) == 1 || dp[i].count(b) == 1)dp[i+1].insert(r);
            }
        }
    }
    cout << ((dp[n].count(0) == 1) ? "Takahashi" : "Aoki") << endl;
    return 0;
}

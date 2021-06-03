#include <bits/stdc++.h>
#include <atcoder/all>
#include <string>
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
    int n, k;
    cin >> n >> k;
    int a = n;
    rep(i,k){
        string s = to_string(a);
        string gs = s; sort(all(gs));
        string fs = s; sort(all(fs), greater<char>());
        a = atoi(fs.c_str()) - atoi(gs.c_str());
    }
    cout << a << endl;
    return 0;
}

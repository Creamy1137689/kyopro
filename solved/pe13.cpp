#include <bits/stdc++.h>
using namespace std;

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
    ll sum = 0;
    rep(i,100){
        string s;
        cin >> s;
        s = s.substr(40, 10);
        sum += atoll(s.c_str());
        if(i == 0)cout << s << endl;
    }
    cout << sum % 10000000000 << endl;
    return 0;
}

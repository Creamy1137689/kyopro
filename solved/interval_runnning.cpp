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
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll distf = (a1-b1)*t1, distl = (a2-b2)*t2;
    if(distf < 0){distf *= -1; distl *= -1;}
    if(distf + distl > 0){
        cout << 0 << endl;
    }else if(distf + distl == 0){
        cout << "infinity" << endl;
    }else{
        cout << 2*((-distf)/(distf+distl)) + (((-distf) % (distf+distl)) != 0) << endl;
    }
    return 0;
}

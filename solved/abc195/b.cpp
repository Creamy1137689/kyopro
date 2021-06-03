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
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    int nin = inf, nax = -1;
    REP(n, 1000000){
        if(a*n <= w && w <= b*n){
            nin = min(nin, n);
            nax = max(nax, n);
        }
    }
    if(nax == -1 && nin == inf){cout << "UNSATISFIABLE" << endl;}
    else cout << nin << ' ' << nax << endl;
    return 0;
}
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
    int a, b;
    cin >> a >> b;
    if(a+b >= 15 && b >= 8)cout << 1 << endl;
    else if(a+b >= 10 && b >= 3)cout << 2 << endl;
    else if(a+b >= 3)cout << 3 << endl;
    else cout << 4 << endl;
    return 0;
}

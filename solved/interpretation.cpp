#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
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
    int n,m;
    cin >> n >> m;
    dsu uf(n+m);
    rep(i,n){
        int k, l;
        cin >> k;
        rep(j, k){
            cin >> l;
            uf.merge(i, n+l-1);
        }
    }
    bool ans = true;
    int led = uf.leader(0);
    rep(i,n){
        if(uf.leader(i) != led)ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}

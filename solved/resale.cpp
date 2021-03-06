#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<' ';
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n; cin>>n;
    vint v(n), c(n);
    rep(i,n) cin>>v[i];
    rep(i,n) cin>>c[i];
    vint vd(n);
    rep(i,n) vd[i] = v[i]-c[i];
    int ans = 0;
    rep(i,n){
        if(vd[i]>0)ans += vd[i];
    }
    cout<<ans<<endl; return 0;
}

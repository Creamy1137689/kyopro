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
#define REP(i,n) for(int i = 1; i<n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    ld a,b,x;cin>>a>>b>>x;
    ld par = x/a;
    ld tri = b/a;
    ll ans = 0;
    for(int i = 1; i<=10; ++i){
        ll tmp = (ll)(par-tri*i);
        if(tmp > 1e9)tmp = 1e9;
        ll l = pow(10,i-1); ll r = pow(10,i);
        if(tmp < l);
        else if(tmp < r)ans = max(ans,tmp);
        else ans = r-1;
    }
    cout<<ans<<endl;
}
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
#define showall(obj) for(auto x:obj)cout<<x<<endl;
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
    vll a(n); rep(i,n)cin>>a[i];
    vll s(n+1); rep(i,n)s[i+1] = s[i]+a[i];

    ll ans = INF;
    ll sum = s[n];
    REP(i,n){
        ans = min(ans, abs(sum-2*s[i]));
    }
    cout<<ans<<endl; return 0;
}

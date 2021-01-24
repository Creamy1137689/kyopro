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
    int n,m;cin>>n>>m;
    int p[n+1][m+1];
    REP(i,n)REP(j,m){
        cin>>p[i][j];
    }
    ll ans = 0;
    for(int j = 1; j<m; ++j){
        for(int k = j+1; k<=m; ++k){
            ll eans = 0;
            REP(i,n){
                eans += max(p[i][j], p[i][k]);
            }
            ans = max(eans, ans);
        }
    }
    cout<<ans<<endl;
}

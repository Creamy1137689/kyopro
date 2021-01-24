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
const int inf = 537427207;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n,m;cin>>n>>m;
    vector<ip> s(n);
    vector<ip> c(m);
    rep(i,n)cin>>s[i].first>>s[i].second;
    rep(i,m)cin>>c[i].first>>c[i].second;
    rep(i,n){
        ll x = s[i].first, y = s[i].second;
        ll eans, mnt = INF;
        rep(j,m){
            ll p = c[j].first, q = c[j].second;
            if(mnt>abs(x-p)+abs(y-q)){eans = j; mnt = abs(x-p)+abs(y-q);}
        }
        cout<<eans+1<<endl;
    }
}

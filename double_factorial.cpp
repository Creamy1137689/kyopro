#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
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
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    ll n; cin>>n;
    if(n%2 == 1){cout<<0<<endl; return 0;}

    vll divisor;
    for(ll now = 5; now<= n; now *= 5)divisor.push_back(now);
    ll ans = 0;
    for(auto x : divisor){
        ans += (n/x)/2;
    }
    cout<<ans<<endl; return 0;
}

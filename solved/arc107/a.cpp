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
#include<atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)998244353;

int main(){
    ll a, b,c;
    cin >> a >> b >> c;
    a = a*(a+1)/2; a %= MOD;
    b = b*(b+1)/2; b %= MOD;
    c = c*(c+1)/2; c%=MOD;
    ll ans = a*b;
    ans %= MOD;
    ans *= c;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}

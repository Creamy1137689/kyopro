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
using namespace std;

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
const int MOD = (int)1e9 + 7;

map<ll,ll> primefactor(ll N){
    map<ll,ll> res;
    for(ll k = 2; k*k <= N; ++k){
        while(N % k == 0){res[k]++; N /= k;}
    }
    if(N != 1)res[N]++;
    return res;
}

ll calc(ll f, ll a){
    ll res;
    for(res = 1; a > 0; ++res){
        ll tmp = 0;
        ll now = f * res;
        while(now % f == 0 && now > 0){
            ++tmp;
            now /= f;
        }
        a -= tmp;
    }
    return res-1;
}

int main(){
    ll N;
    cin >> N;
    map<ll,ll> fact = primefactor(N);
    ll ans = 0;
    for(auto x:fact){
        ans = max(ans, x.first *calc(x.first, x.second));
    }
    cout << ans << endl;
    return 0;
}

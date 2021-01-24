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
const int MOD = (int)1e9 + 7;

int main(){
    ll N;
    cin >> N;
    N *= 2;
    vector<ll> r(2);
    vector<ll> m(2);
    r[0] = 0; r[1] = -1;
    ll ans = INF;
    for(ll i = 1; i*i <= N; i++){
        if(N % i == 0){
            ll j = N / i;
            m[0] = i; m[1] = j;
            LP ans1 = crt(r, m);
            swap(m[0], m[1]);
            LP ans2 = crt(r, m);
            if(ans1.first != 0)ans = min(ans, ans1.first);
            if(ans2.first != 0)ans = min(ans, ans2.first);
        }
    }
    cout << ans << endl;
    return 0;
}

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
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> sums(1000000);
    for(ll t = 2; t < 1000000; ++t){
        if(t <= N)sums[t] = t-1;
        else sums[t] = 2*N-t+1;
    }
    for(ll t = 2; t <= 2*N; ++t){
        ll m = t-K;
        if(2 <= m && m <= 2*N)ans += sums[m]*sums[t];
    }
    cout << ans << endl;
    return 0;
}

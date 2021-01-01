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

int solve(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N*K);
    rep(i, N*K)cin >> a[i];
    sort(all(a));
    ll ans = 0;
    int lat = N/2;
    int r = N*K-1;
    for(int cnt = 0; cnt < K; ++cnt){
        r -= lat;
        ans += a[r];
        --r;
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int T;
    cin >> T;
    rep(_,T)solve();
    return 0;
}

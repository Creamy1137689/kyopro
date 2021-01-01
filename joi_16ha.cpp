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
#include <atcoder/all>
using namespace atcoder;
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

vector<ll> memo(20200, INF);
vector<ll> a(20200);
ll N, M, K;

ll solve(int t){
    if(memo[t] != INF)return memo[t];
    if(t == N)return 0;
    ll res = INF;
    ll rangemax = a[t];
    ll rangemin = a[t];
    REP(i,M){
        int r = t + i - 1;
        if(r >= N)break;
        rangemax = max(rangemax, a[r]);
        rangemin = min(rangemin, a[r]);
        res = min(res, K + i *(rangemax - rangemin) + solve(r + 1));
    }
    return memo[t] = res;
}

int main(){
    cin >> N >> M >> K;
    rep(i,N)cin >> a[i];
    cout << solve(0) << endl;
    return 0;
}

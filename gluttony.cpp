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

bool isOK(vector<ll> &a, vector<ll> &f, ll score, ll try_nax){
    ll trial = 0;
    int N = a.size();
    rep(i,N){
        if(a[i] * f[i] > score){
            ll rest = a[i] * f[i] - score;
            trial += rest / f[i] + (rest % f[i] != 0);
        }
    }
    //printf("[goal_score = %lld] -> [trial = %lld]\n", score, trial);
    return trial <= try_nax;
}

ll BInary_search(vector<ll> &a, vector<ll> &f, ll nax, ll K){
    ll ng = -1;
    ll ok = nax;
    while(abs(ok-ng) > 1){
        ll mid = (ok + ng)/2;
        if(isOK(a, f, mid, K))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), f(N);
    rep(i,N)cin >> a[i];
    rep(i,N)cin >> f[i];
    sort(all(f));
    sort(all(a), greater<ll>());
    cout << BInary_search(a, f, 10000000000000, K) << endl;
    return 0;
}

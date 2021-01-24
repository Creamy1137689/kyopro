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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

long long modpow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    int nap[n][n];
    rep(i,n)rep(j,n)cin >> nap[i][j];
    priority_queue<ll, vector<ll>, greater<ll>> q;
    map<ll, ll> ans;
    set<ll> al;
    ans[0] = 1;
    q.push(0);
    while(!q.empty()){
        ll now = q.top();
        q.pop();
        if(al.count(now) != 0)continue;
        al.insert(now);
        rep(i,n)rep(j,n){
            if(nap[i][j] == 1){
                if((~now) & (1 << i) && (~now) & (1 << (j+n))){
                    ll t = now;
                    t |= (1 << i);
                    t |= (1 << (j + n));
                    ans[t] += ans[now];
                    ans[t] %= MOD;
                    q.push(t);
                }
            }
        }
    }
    ll inv = 1;
    REP(i,n){
        inv *= modpow(i, MOD-2);
        inv %= MOD;
    }
    ll res = ans[(1 << (2*n)) - 1] * inv;
    res %= MOD;
    cout << res << endl;
    return 0;
}

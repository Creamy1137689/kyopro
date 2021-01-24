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
int MOD = (int)1e9 + 7;

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
    int p, N;
    cin >> p >> N;
    MOD = p;
    map<int, int> x, y, z;
    vector<P> cand;
    rep(i,p){
        int d = modpow(i, N); 
        ++x[d]; ++y[d]; ++z[d];
    }
    for(auto xx:x){
        cand.push_back(xx);
    }
    ll ans = 0;
    for(int i = 0; i < cand.size(); ++i){
        for(int j = i; j < cand.size(); ++j){
            int k = cand[i].first + cand[j].first;
            k %= MOD;
            ans += cand[i].second * cand[j].second * z[k] *(i == j ? 1 : 2);
        }
    }
    cout << ans << endl;
    return 0;
}

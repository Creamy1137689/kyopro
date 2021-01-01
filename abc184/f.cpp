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

int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> a(N);
    rep(i,N)cin >> a[i];
    set<ll> one;
    set<ll> sec;
    int one_part = N/2;
    int sec_part = N-one_part;
    for(int bit = 0; bit < (1<< one_part); ++bit){
        ll sum = 0;
        rep(i,one_part){
            if(bit & (1 << i))sum += a[i];
        }
        one.insert(sum);
    }
    for(int bit = 0; bit < (1<< sec_part); ++bit){
        ll sum = 0;
        rep(i,sec_part){
            if(bit & (1 << i))sum += a[i+one_part];
        }
        sec.insert(sum);
    }
    ll ans = 0;
    for(auto x:one){
        ll need = T - x;
        auto it = sec.upper_bound(need);
        if(it == sec.begin())continue;
        --it;
        ans = max(ans, x + *it);
    }
    cout << ans << endl;
    return 0;
}

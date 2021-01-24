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

struct s{int l, r, x;};

int main(){
    int n, m;
    cin >> n >> m;
    vector<s> query(m);
    rep(i,m)cin >> query[i].l >> query[i].r >> query[i].x;
    int ans = -1;
    rep(bit, (1 << n)){
        vector<bool> pep(n);
        int pans = 0;
        rep(i,n){
            if(bit & (1 << i)){pep[i] = true; ++pans;}
        }
        bool ok = true;
        rep(i,m){
            int cnt = 0;
            for(int p = query[i].l - 1; p <= query[i].r - 1; ++p){
                if(pep[p])++cnt;
            }
            if(cnt != query[i].x)ok = false;
        }
        if(ok){ans = max(ans, pans);cout << bit << endl;}
    }
    cout << ans << endl;
    return 0;
}

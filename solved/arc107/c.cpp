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
const int MOD = (int)998244353;

int main(){
    ll N, K;
    cin >> N >> K;
    int a[55][55];
    rep(i,N)rep(j,N)cin >> a[i][j];
    dsu row(N), col(N);
    rep(x,N)rep(y,N){
        bool ok = true;
        rep(i,N)if(a[i][x] + a[i][y] > K)ok = false;
        if(ok)col.merge(x,y);
    }
    rep(x,N)rep(y,N){
        bool ok = true;
        rep(i,N)if(a[x][i] + a[y][i] > K)ok = false;
        if(ok)row.merge(x,y);
    }

    vector<ll> fact(60,1);
    REP(i,59)fact[i] = i*fact[i-1], fact[i] %= MOD;
    set<int> al_row;
    set<int> al_col;
    ll ans = 1;
    rep(i,N){
        if(al_row.count(row.leader(i)) == 0){
            ans *= fact[row.size(i)];
            ans %= MOD;
            al_row.insert(row.leader(i));
        }
    }
    rep(i,N){
        if(al_col.count(col.leader(i)) == 0){
            ans *= fact[col.size(i)];
            ans %= MOD;
            al_col.insert(col.leader(i));
        }
    }
    cout << ans << endl;
    return 0;
}

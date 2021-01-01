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
    ll N, M, c,d;
    cin >> N >> M;
    vector<ll> a(N), b(N);
    dsu uf(N);
    rep(i,N)cin >> a[i];
    rep(i,N)cin >> b[i];
    rep(i,M){
        cin >> c >> d;
        --c; --d;
        uf.merge(c,d);
    }
    map<ll, ll> excount;
    map<ll, ll> idealcount;
    rep(i,N){
        int to = uf.leader(i);
        excount[to] += a[i];
        idealcount[to] += b[i];
    }
    bool ans = true;
    for(auto x:excount){
        if(idealcount[x.first] != x.second)ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

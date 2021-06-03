#include <atcoder/segtree.hpp>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int op(int a, int b){return min(a, b);}
int e(){return inf;}

int main(){
    int MAX = 1500100;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    segtree<int, op, e> seg(MAX);
    rep(i,MAX)seg.set(i, i);

    int ans = inf;
    map<int,int> exist;
    rep(i,m-1){
        seg.set(a[i], inf);
        exist[a[i]]++;
    }
    for(int i = 0; i + m <= n; ++i){
        seg.set(a[i+m-1], inf);
        exist[a[i+m-1]]++;
        ans = min(ans, seg.prod(0, MAX));
        exist[a[i]]--;
        if(exist[a[i]] == 0)seg.set(a[i], a[i]);
    }

    cout << ans << endl;
    return 0;
}

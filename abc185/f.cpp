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

int op(int a, int b){return a ^ b;}

int e(){return 0;}

int main(){
    int N, Q, a, t, x, y;
    cin >> N >> Q;
    segtree<int, op, e> seg(N);
    rep(i,N){
        cin >> a;
        seg.set(i, a);
    }
    rep(i,Q){
        cin >> t >> x >> y;
        if(t == 1){
            seg.set(x-1, seg.get(x-1)^y);
        }else{
            cout << seg.prod(x-1, y) << endl;;
        }
    }
    return 0;
}

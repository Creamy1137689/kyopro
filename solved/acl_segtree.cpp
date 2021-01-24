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

int op(int a, int b){return max(a,b);}
int e(){return 0;}
int v;
bool comp(int inp){ return inp < v;}

int main(){
    int N, Q, a, com, x, l, r;
    cin >> N >> Q;
    segtree<int, op, e> seg(N);
    rep(i,N){
        cin >> a;
        seg.set(i,a);
    }
    rep(_,Q){
        cin >> com;
        if(com == 1){
            cin >> x >> v;
            --x;
            seg.set(x,v);
        }else if(com == 2){
            cin >> l >> r;
            --l;
            cout << seg.prod(l, r) << endl;
        }else{
            cin >> x >> v;
            --x;
            cout << seg.max_right(x, comp) + 1 << endl;
        }
    }
    return 0;
}

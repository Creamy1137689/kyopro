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
    int N, Q, a, com, l, r;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    rep(i,N){
        cin >> a;
        fw.add(i, a);
    }
    rep(_,Q){
        cin >> com >> l >> r;
        if(com == 0)fw.add(l, r);
        else cout << fw.sum(l,r) << endl;
    }
    return 0;
}

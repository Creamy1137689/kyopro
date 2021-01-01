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

int e(){return 0;}

int op(int a, int b){return a + b;}

int main(){
    int N, Q, com, p, l, r;
    char c;
    string s;
    cin >> N >> s >> Q;
    vector<segtree<int, op, e>> segvec(26);
    rep(i,26)segvec[i] = segtree<int, op, e> (N);
    rep(i,N){
        segvec[s[i]-'a'].set(i, 1);
    }
    rep(_,Q){
        cin >> com;
        if(com == 1){
            cin >> p >> c;
            --p;
            segvec[s[p]-'a'].set(p, 0);
            segvec[c-'a'].set(p, 1);
            s[p] = c;
        }else{
            cin >> l >> r;
            --l;
            int res = 0;
            rep(i,26){
                res += (segvec[i].prod(l, r) > 0);
            }
            cout << res << endl;
        }
    }
    return 0;
}

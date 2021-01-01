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

class UnionFind{
    vector<ll> par; vector<ll> r_size; vector<ll> rank;
    public:
        UnionFind(ll N) : par(N),r_size(N),rank(N){
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1; rank[i] = 0;}
        }

        //Nの大きさで初期化
        void init(ll N){
            par.resize(N); r_size.resize(N);
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        ll root(ll x){
            if(par[x] == x)return x;
            return par[x]=root(par[x]);
        }

        //xとyとが所属する集合を併呑する
        void merge(ll x,ll y){
            ll rx = root(x); ll ry = root(y);
            if(rx == ry) return;
            if(rank[rx] < rank[ry]) swap(rx,ry);
            if(rank[rx] == rank[ry]) ++rank[rx];
            r_size[rx] += r_size[ry];
            par[ry] = rx;
        }

        bool same(ll x, ll y){
            return root(x) == root(y);
        }

        //素集合の大きさを返す
        ll size(ll x){
            return r_size[root(x)];
        }
};

int main(){
    int N,M,a,b;
    cin >> N >> M;
    UnionFind uf(N);
    rep(i, M){
        scanf("%d %d", &a, &b);
        --a; --b;
        uf.merge(a,b);
    }
    set<int> ans;
    rep(i, N)ans.insert(uf.root(i));
    cout << ans.size() - 1 << endl;
    return 0;
}

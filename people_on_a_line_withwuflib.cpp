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


template<class Abel> class WeightedUnionFind{
    vector<int> par; 
    vector<int> r_size; 
    vector<int> rank; 
    vector<Abel> diff_weight;
    public:
        WeightedUnionFind(int N, Abel SUM_UNITY = 0){
            init(N, SUM_UNITY);
        }

        void init(int N, Abel SUM_UNITY = 0){
            par.resize(N); r_size.resize(N); rank.resize(N); diff_weight.resize(N);
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1; rank[i] = 0; diff_weight[i] = SUM_UNITY; }
        }

        int root(int x){
            if(par[x] == x)return x;
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }

        Abel get_weight(int x){
            root(x);
            return diff_weight[x];
        }

        Abel diff(int x, int y){
            return get_weight(y) - get_weight(x);
        }

        //xとyとが所属する集合を併呑する
        //なお，weight(y) - weight(x) = wとなるようにmerge
        bool merge(int x, int y, Abel w){
            w += get_weight(x); w -= get_weight(y);
            int rx = root(x),  ry = root(y);
            if(rx == ry) return false;
            if(rank[rx] < rank[ry]) swap(rx,ry), w = -w;
            if(rank[rx] == rank[ry]) ++rank[rx];
            r_size[rx] += r_size[ry];
            par[ry] = rx;
            diff_weight[ry] = w;
            return true;
        }

        bool same(int x, int y){
            return root(x) == root(y);
        }

        //素集合の大きさを返す
        int size(int x){
            return r_size[root(x)];
        }
};

int main(){
    int N, M, l, r, d;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N,0);
    bool ans = true;
    rep(_,M){
        cin >> l >> r >> d;
        --l; --r;
        if(uf.same(l,r) && abs(uf.diff(l,r)) != d)ans = false;
        uf.merge(l,r,d);
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

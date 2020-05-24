#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<n; ++i)
#define pair pair<int,int>
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int mod = (int)1e9 + 7;
const ll MOD = 92709568269121;

class UnionFind{
    vector<ll> par; vector<ll> r_size;
    public:
        UnionFind(ll N) : par(N),r_size(N){
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        //Nの大きさで初期化
        void init(ll N){
            par.resize(N); r_size.resize(N);
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        ll find(ll x){
            if(par[x] == x)return x;
            return par[x]=find(par[x]);
        }

        //xとyとが所属する集合を併呑する
        void unite(ll x,ll y){
            ll rx = find(x); ll ry = find(y);
            if(rx == ry) return;
            if(r_size[rx]<r_size[ry]) swap(rx,ry);
            r_size[rx] += r_size[ry];
            par[ry] = rx;
        }

        bool same(ll x, ll y){
            ll ry = find(x); ll rx = find(y);
            return rx == ry;
        }

        //素集合の大きさを返す
        ll el_size(ll x){
            return r_size[find(x)];
        }
};

int main(){
    ll n,m,a,b; cin>>n>>m;
    vector<pair> input(m);
    rep(i,m){ cin>>a>>b; input[i].first = --a; input[i].second = --b;}

    UnionFind island(n);
    vector<ll> ans(m);

    ans[0] = (n*(n-1))/2;
    reverse(input.begin(),input.end());

    ll x,y; ll con;
    rep(i,m-1){
        x = input[i].first; y = input[i].second;
        if(island.same(x,y)){
            ans[i+1] = ans[i];
        }else{
            con = island.el_size(x)*island.el_size(y);
            ans[i+1] = max(ans[i]-con, 0LL);
            island.unite(x,y);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<endl; return 0;
}

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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

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

bool compare_second(const ip& ip1, const ip& ip2){
    return ip1.second <ip2.second;
}

int main(){
    int n,m,x,y,t; cin>>n>>m;
    vector<ip> p(n); rep(i,n){cin>>t; p[i].first = i; p[i].second = --t;}
    vector<ip> pairs(m); rep(i,m){ cin>>x>>y; pairs[i].first = --x; pairs[i].second = --y;}

    vector<ip> ele(n); ele = p;
    sort(ele.begin(),ele.end(),compare_second);

    UnionFind uf(n);
    rep(i,m)uf.unite(pairs[i].first,pairs[i].second);
    int ans = 0;
    rep(i,n){
        if(p[i].second == i)++ans;
        else if(uf.same(p[i].first, p[ele[i].first].first))++ans;
    }
    cout<<ans <<endl; return 0;

}

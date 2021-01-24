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
const int MOD = (int)1e9 + 7;

class UnionFind{
    vector<int> par; vector<int> rank;
    public:
        UnionFind(int N) : par(N),rank(N){
            for(int i=0; i<N; ++i){ par[i] = i; rank[i] = 0; }
        }

        int find(int x){
            if(par[x] == x)return x;
            return par[x]=find(par[x]);
        }

        //xとyとが所属する集合を併呑する
        void unite(int x,int y){
            int rx = find(x); int ry = find(y);
            if(rx == ry) return;
            if(rank[x]<rank[y]){
                par[rx] = ry;
            }else{
                par[ry] = rx;
                if(rank[rx] == rank[ry])rank[rx]++;
            }
        }

        bool same(int x, int y){
            int ry = find(x); int rx = find(y);
            return rx == ry;
        }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,k,l; cin>>n>>k>>l; int p,q;
    UnionFind road(n); rep(i,k){ cin>>p>>q; road.unite(--p,--q); }
    UnionFind rail(n); rep(i,l){ cin>>p>>q; rail.unite(--p,--q); }

    map<pair,int> ans;
    rep(i,n)ans[{road.find(i),rail.find(i)}]++;
    rep(i,n)cout<<ans[{road.find(i),rail.find(i)}]<<' '; return 0;
}

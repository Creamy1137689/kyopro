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
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

class UnionFind{
    vector<int> par; vector<int> r_size;
    public:
        UnionFind(int N) : par(N),r_size(N){
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        void init(int N){
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        int find(int x){
            if(par[x] == x)return x;
            return par[x]=find(par[x]);
        }

        //xとyとが所属する集合を併呑する
        void unite(int x,int y){
            int rx = find(x); int ry = find(y);
            if(rx == ry) return;
            if(r_size[rx]<r_size[ry]) swap(rx,ry);
            r_size[rx] += r_size[ry];
            par[ry] = rx;
        }

        bool same(int x, int y){
            int ry = find(x); int rx = find(y);
            return rx == ry;
        }

        int el_size(int x){
            return r_size[find(x)];
        }
};

int main(){
    int n,m; cin>>n>>m; int a,b;
    vector<ip> input(m); rep(i,m){cin>>a>>b; input[i].first = --a; input[i].second = --b;}

    int ans = 0;
    rep(i,m){
        UnionFind graph(n);
        rep(j,m){
            if(j != i)graph.unite(input[j].first,input[j].second);
        }
        if(graph.el_size(0) < n)ans++;
    }
    cout<<ans<<endl; return 0;
}
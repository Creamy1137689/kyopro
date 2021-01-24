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
    int N,Q; cin>>N>>Q;
    UnionFind set(N);

    int p,a,b;
    rep(i,Q){
        cin>>p>>a>>b;
        if(p==0){ set.unite(a,b);}
        else{cout<<((set.same(a,b))?"Yes":"No") <<endl;}
    }
}

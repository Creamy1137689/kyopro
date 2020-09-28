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
    vector<ll> par; vector<ll> r_size;
    public:
        UnionFind(ll N) : par(N),r_size(N){
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        void init(ll N){
            par.resize(N); r_size.resize(N);
            for(int i=0; i<N; ++i){ par[i] = i; r_size[i] = 1;}
        }

        ll find(ll x){
            if(par[x] == x)return x;
            return par[x]=find(par[x]);
        }

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

        ll el_size(ll x){
            return r_size[find(x)];
        }
};

int main(){
	ll N, M, a, b;
	cin >> N >> M;
	UnionFind uf(N);
	vector<P> path(M);
	vector<ll> ans(M+1);
	ans[M] = N*(N-1)/2;
	rep(i,M){
		cin >> a >> b;
		--a; --b;
		path[i] = make_pair(a,b);
	}
	for(int i = M-1; i >= 0; --i){
		ll res = ans[i+1];
		if(!uf.same(path[i].first, path[i].second)){
			res -= uf.el_size(path[i].first) * uf.el_size(path[i].second);
			uf.unite(path[i].first, path[i].second);
		}
		ans[i] = res;
	}
	REP(i,M)cout << ans[i] << endl;
	return 0;
}

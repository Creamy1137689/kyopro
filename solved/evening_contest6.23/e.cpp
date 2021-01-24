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
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

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
	int N,M,x,y;
	cin>>N>>M;
	UnionFind un(N);
	vector<int> p(N);
	rep(i,N)cin>>p[i];
	rep(i,M){
		cin>>x>>y;
		--x; --y;
		un.unite(x, y);
	}
	vector<set<int>> cnt(N);
	rep(i,N){
		cnt[un.find(i)].insert(p[i]);
	}
	int ans = 0;
	rep(i,N){
		if(cnt[un.find(i)].count(i+1) == 1) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}
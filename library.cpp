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

//マップ検索用
int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};
int d8x[8] = {0,1,1,1,0,-1,-1,-1};
int d8y[8] = {1,1,0,-1,-1,-1,0,1};

/*------------------------------
| 数学的ライブラリ               |
------------------------------*/

//GCD最大公約数を求める（不要なり）
int gcd(int a,int b){
    if(a<b){int tmp=a;a=b;b=tmp;}
    while(a%b!=0){int tmp=a%b;a=b;b=tmp;} return b;
}

//繰り返しn乗法……aをn乗したもののMOD(M)をとる
ll rep_power_modM(ll a, ll n, ll M){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

//組み合わせ……n個の中からr個選ぶ "rep_power_modM" 使用
ll comb(ll n, ll r, ll M = MOD){
    ll ans = 1; rep(i,r){ans *= (n-i)%M; ans%=M;}
    ll divisor = 1; rep(i,r){divisor *= (i+1)%MOD; divisor %=M;}
    ans = ans * rep_power_modM(divisor,M-2,M)%M; if(ans<0)ans+=M;
    return ans;
}

/*------------------------------
| 二分探索                      |
------------------------------*/



/*------------------------------
| 以下DPで使用する関数群         |
------------------------------*/

//aとbのうち小さい値をaとして採用する
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

//aとbのうち大きい値をaとして採用する
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

/*------------------------------
| UnionFind木の実装             |
------------------------------*/

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
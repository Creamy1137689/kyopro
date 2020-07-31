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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

//ModInt
const int mod = 1000000007;
const int mod = 998244353;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


//マップ検索用
int d4x[4] = {0,1,0,-1};
int d4y[4] = {1,0,-1,0};
int d8x[8] = {0,1,1,1,0,-1,-1,-1};
int d8y[8] = {1,1,0,-1,-1,-1,0,1};

/*------------------------------
| ソート拡張                    |
|  sort, reverse              |
------------------------------*/

//pairの second->first の順番でソート
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

//絶対値降順
bool comp_abs(int a, int b){
    return abs(a) < abs(b);
}


/*------------------------------
| 数学的ライブラリ              |
|  math, calc                 |
------------------------------*/

//GCD最大公約数を求める（不要なり）
int gcd(int a,int b){
    if(a<b){int tmp=a;a=b;b=tmp;}
    while(a%b!=0){int tmp=a%b;a=b;b=tmp;} return b;
}

//複数の最小公倍数
ll lcm(vector<ll> a, int p, ll ans = 1LL){
    if(p>=a.size())return ans;
    ans = a[p]/__gcd(ans, a[p])*ans;
    ans = lcm(a, p+1, ans);
    return ans;
}

//繰り返しn乗法……aをn乗したもののMOD(M)をとる
ll rep_power_modM(ll a, ll n, ll M = MOD){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

//組み合わせ……n個の中からr個選ぶ "rep_power_modM" 使用
ll comb_modM(ll n, ll r, ll M = MOD){
    ll ans = 1; rep(i,r){ans *= (n-i)%M; ans%=M;}
    ll divisor = 1; rep(i,r){divisor *= (i+1)%MOD; divisor %=M;}
    ans = ans * rep_power_modM(divisor,M-2,M)%M; if(ans<0)ans+=M;
    return ans;
}

// 数値微分…fnは微分したい関数, xは座標, hは微小値(デフォルトで10^-9)
template<class Fn> long double differentiate(Fn fn, long double x, long double h = 0.000000001){
    long double ans;
    ans = (fn(x+h)-fn(x-h))/(2*h);
    return ans;
}

// 素因数分解…nを素因数分解した結果をmap<ll, ll>で返す
map<ll, ll> prime_factor(ll n){
    map<ll,ll> com;
    for(ll i = 2LL; i*i<=n; ++i){
        while(n%i==0LL){
            com[i]++;
            n /= i;
        }
    }
    if(n != 1LL)com[n]++;
    return com;
}

// 素数判定
bool isprime(ll n){
    if(n==0LL || n==1LL){return false;}
    bool ok = true;
    for(ll i = 2LL; i*i <= n; ++i){if(n%i==0){ok = false; break;}}
    return ok;
}

// 素数列挙
void enumerate_prime(vector<bool> &a){
    a[0] = false; a[1] = false;
    for(int i = 2; i*i<=a.size(); ++i){
        if(a[i]){ for(int j = 2; i*j<=a.size()-1; ++j){ a[i*j] = false; }}
    }
}

/*------------------------------
| 二分探索                      |
------------------------------*/

bool isOK(int a[], int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int binary_search(int a[], int nax, int key){
    int ng = -1;
    int ok =nax;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(a,mid,key))ok = mid;
        else ng = mid;
    }
    return ok;
}


/*------------------------------
| Graph Algolythm              |
------------------------------*/


vector<vector<int>> G(200100, vector<int>()); 

//UnweightedTree
//To find Diameter, use this func two times 
//argument -> [Vertex_Size, Start_Node]
//return   -> [Furthest_Node, Furthest_Distance]
P tree_diameter(int V, int st){
	int t = st;
	int diameter = 0;
	queue<int> Q;
	vector<int> dist(V, inf);
	dist[st] = 0;
	Q.push(st);
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto x:G[f]){
			if(dist[x] == inf){
				dist[x] = dist[f] + 1;
				Q.push(x);
				if(dist[x] > diameter){
					diameter = dist[x];
					t = x;
				}
			}
		}
	}
	return make_pair(t, diameter);
}


/*------------------------------
| DP                           |
------------------------------*/

//aとbのうち小さい値をaとして採用する
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

//aとbのうち大きい値をaとして採用する
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

/*------------------------------
| UnionFind木の実装           |
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

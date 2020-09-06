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
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 数値微分…fnは微分したい関数, xは座標, hは微小値(デフォルトで10^-9)
template<class Fn> long double differentiate(Fn fn, long double x, long double h = 0.000000001){
    long double ans;
    ans = (fn(x+h)-fn(x-h))/(2*h);
    return ans;
}

// 素因数分解…nを素因数分解した結果をmap<ll, ll>で返す
// 計算量はO(logN)
// 使用する前にinit_min_primefactorを実行
int PRIMES_MAX = 10000000;
vector<int> min_primefactor(PRIMES_MAX, inf);

void init_min_primefactor(){
	min_primefactor[0] = 0;
	min_primefactor[1] = 1;
	for(int i = 2; i < PRIMES_MAX; ++i){
		if(min_primefactor[i] == inf){
			for(int k = 1; i * k < PRIMES_MAX; ++k){
				min_primefactor[i * k] = i;
			}
		}
	}
}

map<int,int> prime_factor(int N){
	map<int, int> res;
	while(N > 1){
		res[min_primefactor[N]]++;
		N /= min_primefactor[N];
	}
	return res;
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
| 幾何系 Geometry              |
------------------------------*/
// is cross
double f(P x, P y, P z){
	return (y.second - x.second)*(z.first - x.first) - (y.first - x.first)*(z.second - x.second);
}

bool is_cross(P x, P y, P z, P w){
	double t1 = f(x, y, z);
	double t2 = f(x, y, w);
	double t3 = f(z, w, x);
	double t4 = f(z, w, y);
	return (t1*t2 <= 0 && t3*t4 <= 0);
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

//.............UnweightedTree............//
//To find Diameter, use this func two times 
//argument -> [Vertex_Size, Start_Node]
//return   -> [Furthest_Node, Furthest_Distance]
vector<vector<int>> G(200100, vector<int>()); 
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


//........WeightedGraph.................//
//Dijkstra法による最短経路
//グラフは[to, cost]の重み付きグラフ
vector<vector<P>> wG(1010, vector<P>());

void dijkstra(int start, vector<int> &dist){
	priority_queue<P, vector<P>, greater<P>> Q;
	Q.emplace(0, start);
	dist[start] = 0;
	while(!Q.empty()){
		int cost = Q.top().first;
		int f = Q.top().second;
		Q.pop();
		if(cost > dist[f])continue;
		for(auto t:wG[f]){
			if(dist[t.first] > cost + t.second){
				dist[t.first] = cost + t.second;
				Q.emplace(dist[t.first], t.first);
			}
		}
	}
}

/*------------------------------
| DP                           |
------------------------------*/

//aとbのうち小さい値をaとして採用する
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

//aとbのうち大きい値をaとして採用する
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

//LCS(Longest Common Subsequence)
//復元
string lcs(string a, string b){
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
	vector<vector<P>> transition(a.size()+1, vector<P>(b.size()+1));
	REP(i,a.size()){
		REP(j,b.size()){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				transition[i][j] = make_pair(i-1, j-1);
			}else{
				if(chmax(dp[i][j], dp[i-1][j]))transition[i][j] = make_pair(i-1, j);
				if(chmax(dp[i][j], dp[i][j-1]))transition[i][j] = make_pair(i, j-1);
			}
		}
	}
	string res;
	int i = a.size(), j = b.size();
	while(true){
		if(i == 0 || j == 0)break;
		if(a[i-1] == b[j-1])res.push_back(a[i-1]);
		P from = transition[i][j];
		i = from.first;
		j = from.second;
	}
	reverse(all(res));
	return res;
}

//length
int lcs_len(string a, string b){
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
	REP(i,a.size()){
		REP(j,b.size()){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				chmax(dp[i][j], dp[i-1][j]);
				chmax(dp[i][j], dp[i][j-1]);
			}
		}
	}
	return dp[a.size()][b.size()];
}


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

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
typedef boost::multiprecision::cpp_int lint;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

/* ================ */
/* Prime */
/* ================ */

//IsPrime
//O(sqrt(x))
template<typename T>
bool isprime(T x){
    if(x <= 1)return false;
    for(T i=2; i*i <= x; ++i){
        if(!(x%i))return true;
    }
    return false;
}

//PrimeFactor-1
//smallest prime factor
//Pre : O(N log log N)
//Query : O(log N)
template <typename T>
struct primefactor{
    vector<T> spf;
    primefactor(T n){ init(n); }
    void init(T n){
        spf.assign(n+1, 0);
        for(T i = 0; i <= n; ++i)spf[i] = i;
        for(T i = 2; i*i <= n; ++i){
            if(spf[i] == i){
                for(T j = i*i; j <= n; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n){
        map<T, T> m;
        while(n != 1){
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};


//PrimeFactor-2
//O(sqrt(N))
template <typename T>
vector<pair<T,T>> prime_factor(T n){
    vector<pair<T,T>> m;
    for(T i = 2; i*i <= n; ++i){
        T c = 0;
        while(n % i == 0){
            n /= i; c++;
        }
        if(c > 0)m.emplace_back(i, c);
    }
    if(n != 1)m.emplace_back(n, 1);
    return m;
}


//PrimeFactor-3
//MillerRavin
//Pollard-Rho-Method
//O(N^(1/4))
//Tには多倍長整数(<boost/multipricition/cpp_int.hpp> -> cpp_int)が望ましい
//それ以外は極端に遅くなる可能性あり
template <typename T>
struct HuristicPrime{
    vector<T> divs{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    const int ub = 1048576;
    HuristicPrime(){}
    public:
        vector<pair<T,T>> prime_factor(T n){
            vector<pair<T,T>> res;
            T i = 2;
            bool rho = false;
            while(i*i <= n){
                int cnt = 0;
                while(n % i == 0){
                    n /= i; ++cnt;
                }
                if(cnt)res.emplace_back(i, cnt);
                i += 1 + i%2;
                if(i == 101 && n >= ub){
                    while(n > 1){
                        if(is_prime(n)){
                            res.emplace_back(n, 1); n = 1;
                        }else{
                            rho = true;
                            T j = pollard_rho(n);
                            cnt = 0;
                            while(n % j == 0){
                                n /= j; ++cnt;
                            }
                            res.emplace_back(j, cnt);
                        }
                    }
                }
            }
            if(n > 1)res.emplace_back(n, 1);
            if(rho)sort(res.begin(), res.end());
            return res;
        }

        bool is_prime(T n){
            if(n == 2)return true;
            if(n == 1 || n == 0)return false;
            T d = (n-1) >> 1;
            while((d & 1) == 0){d >>= 1;}
            for(auto a:divs){
                if(a == n)return true;
                T t = d;
                T y = modpow(a, t, n);
                while(t != n-1 && y != 1 && y != n-1){
                    y = (y*y) % n;
                    t <<= 1;
                }
                if(y != n-1 && (t & 1) == 0)return false;
            }
            return true;
        }

    private:
        int dig2(T n){
            int res = 1;
            while(n > 1){++res; n = n >> 1;}
            return res;
        }
        T pollard_rho(T n){
            T m = 1 << dig2(n) / 8;
            for(T c = 1; c < 100; ++c){
                auto f = [n, c](T x) {return (x*x + c) % n;};
                T y = 2, r = 1, q = 1, g = 1;
                T x, ys;
                while(g == 1){
                    x = y;
                    for(T i = 0; i < r; ++i){y = f(y);}
                    T k = 0;
                    while(k < r && g == 1){
                        ys = y;
                        for(T i = 0; i < min(m, r-k); ++i){
                            y = f(y);
                            q = q*abs(x - y) % n;
                        }
                        g = gcd(q, n);
                        k += m;
                    }
                    r <<= 1;
                }
                if(g == n){
                    g = 1;
                    while(g == 1){
                        ys = f(ys);
                        g = gcd(abs(x - ys), n);
                    }
                }
                if(g < n){
                    if(is_prime(g))return g;
                    else if(is_prime(n / g))return n / g;
                    else return pollard_rho(g);
                }
            }
        }
        T modpow(T x, T n, T mod) {
            T ret = 1;
            while (n > 0) {
                if (n & 1) ret = ret * x % mod;
                x = x * x % mod;
                n >>= 1;
            }
            return ret;
        }
};



//Count all prime_factors
template<typename T>
struct primefactor2{
    vector<T> primes_size;
    primefactor2(T n){
        primes_size.resize(n+1, 0);
        for(T i = 2; i <= n; ++i){
            if(primes_size[i] == 0){
                for(T j = i; j <= n; j += i){
                    ++primes_size[j];
                }
            }
        }
    }
    int get_prime_factor_size(T i){return primes_size[i];}
};



//Extended-Gcd
template<typename T>
T extgcd(T a, T b, T &x, T &y){
    T d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}



/* ================ */
/* matrix */
/* ================ */

template<typename T>
vector<vector<T>> mat_idmat(int n){
    vector<vector<T>> res(n, vector<T>(n));
    rep(i,n)res[i][i] = 1;
    return res;
}

//show the contents of matrix
template<typename T>
void mat_show(vector<vector<T>> a){
    rep(i, a.size()){
        rep(j, a[0].size())cout << a[i][j] << ' ';
        cout << endl;
    }
}

//matrix product
//a(n, m) x b(m, l)
template<typename T>
vector<vector<T>> mat_prod(vector<vector<T>> a, vector<vector<T>> b){
    assert(a[0].size() == b.size());
    vector<vector<T>> res(a.size(), vector<T>(b[0].size(), 0));
    rep(i,a.size())rep(k,a[0].size()){
        rep(j,b[0].size()){
            res[i][j] += a[i][k]*b[k][j];
        }
    }
    return res;
}

//matrix pow
template<typename T>
vector<vector<T>> mat_pow(vector<vector<T>> a, ll n){
    if(n == 0)return mat_idmat<T>(a.size());
    vector<vector<T>> res = mat_pow(a, n/2);
    res = mat_prod(res, res);
    if(n % 2 == 1)res = mat_prod(a, res);
    return res;
}

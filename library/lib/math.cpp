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
#include <cassert>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

//prime
template<typename T>
bool isprime(T x){
    if(x <= 1)return false;
    for(T i=2; i*i <= x; ++i){
        if(!(x%i))return true;
    }
    return false;
}


//ext_gcd
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


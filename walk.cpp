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
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

typedef vector<vector<ll>> mat;
mat id_mat(int n){
    mat res(n, vector<ll>(n));
    rep(i,n)res[i][i] = 1;
    return res;
}
mat pr(mat a, mat b){
    mat res(a.size(), vector<ll>(b[0].size(), 0));
    rep(i,a.size())rep(j,b[0].size()){
        rep(k,a[0].size()){
            res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
        }
    }
    return res;
}

mat matpow(mat x, long long n) {
    if(n == 0)return id_mat(x.size());
    if(n % 2 == 1){
        mat k = matpow(x, n/2);
        return pr(x, pr(k, k));
    }else{
        mat k = matpow(x, n/2);
        return pr(k, k);
    }
}

int main(){
    int n;
    ll k;
    cin >> n >> k;
    mat a(n, vector<ll>(n));
    rep(i,n)rep(j,n)cin >> a[i][j];
    mat m = matpow(a, k);
    ll ans = 0;
    rep(i,n)rep(j,n)ans = (ans + m[i][j]) % MOD;
    cout << ans << endl;
    return 0;
}

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

typedef vector<vector<ll>> mat;
void mat_show(mat a){
    rep(i, a.size()){
        rep(j, a[0].size())cout << a[i][j] << ' ';
        cout << endl;
    }
}

mat pr(mat a, mat b){
    mat res(a.size(), vector<ll>(b[0].size(), 0));
    rep(i,a.size())rep(k,a[0].size()){
        rep(j,b[0].size()){
            res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
        }
    }
    return res;
}

int main(){
    mat a = {{2, 3}, {1, 4}, {2, 1}};
    mat b = {{3, 1, 2}, {2, 4, 2}};
    mat_show(mat_prod(a, b));
    return 0;
}

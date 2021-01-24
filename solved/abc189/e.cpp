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
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;


typedef vector<vector<ll>> mat;

mat gen_mat(int com, int p){
    if(com == 1){
        return {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    }else if(com == 2){
        return {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    }else if(com == 3){
        return {{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}};
    }else{
        return {{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}};
    }
}


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

int main(){
    int n;
    cin >> n;
    vector<LP> dot(n);
    rep(i,n)cin >> dot[i].first >> dot[i].second;
    int m;
    cin >> m;
    vector<mat> ops(m+1);
    ops[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    rep(i,m){
        int com, p = 0;
        cin >> com;
        if(com >= 3)cin >> p;
        ops[i+1] = mat_prod(gen_mat(com, p), ops[i]);
    }
    int q;
    cin >> q;
    rep(i,q){
        int a, b;
        cin >> a >> b;
        --b;
        mat res = mat_prod(ops[a], {{dot[b].first}, {dot[b].second}, {1}});
        cout << res[0][0] << ' ' << res[1][0] << endl;
    }
    return 0;
}

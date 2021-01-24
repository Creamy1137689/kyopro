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
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

double f(double p, vector<double>& a, vector<double>& c){
    double r = -inf;
    rep(i,a.size()){
        r = max(r, abs(a[i]-p) * c[i]);
    }
    return r;
}

double tarnary_search(vector<double>& a, vector<double>& c){
    double high = 100100;
    double low = -100100;
    rep(_, 500){
        double ml = high/3 + low*2/3;
        double mr = high*2/3 + low/3;
        if(f(ml, a, c) >= f(mr, a, c))low = ml;
        else high = mr;
    }
    return high;
}

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    vector<double> y(n);
    vector<double> c(n);
    rep(i,n)cin >> x[i] >> y[i] >> c[i];
    double xc = tarnary_search(x, c);
    double yc = tarnary_search(y, c);
    cout  << fixed << setprecision(10) << max(f(xc, x, c), f(yc, y, c)) << endl;
    return 0;
}

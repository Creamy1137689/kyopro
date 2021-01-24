#include <algorithm>
#include <bits/stdc++.h>
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

/* ============== */
/* Binary Search */
/* ============== */

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



/* ============== */
/* Tarnary Search */
/* ============== */

double f(double p){
    double r = 0;
    return r;
}

double tarnary_search(double high, double low){
    rep(_, 500){
        double ml = high/3 + low*2/3;
        double mr = high*2/3 + low/3;
        if(f(ml) >= f(mr))low = ml;
        else high = mr;
    }
    return high;
}

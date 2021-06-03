#include <algorithm>
#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using namespace boost::multiprecision;

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

typedef cpp_int lint;

string x;
lint m;

bool isOK(lint b){
    lint sum = 0;
    lint mul = 1;
    rep(i, x.size()){
        sum += mul * (x[i]-'0');
        mul *= b;
    }
    /* cout << b << ' ' << sum << endl; */
    if(sum <= m)return true;
    else return false;
}

lint binary_search(int d){
    lint ng = 1000000000000001000;
    lint ok = d;
    while(abs(ok-ng) > 1){
        lint mid = (ok + ng)/2;
        if(isOK(mid))ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> x >> m;
    if(x.size() == 1){
        if(x[0]-'0' <= m){cout << 1 << endl;}
        else {cout << 0 << endl;}
        return 0;
    }
    reverse(all(x));
    int d = 0;
    rep(i,x.size())if(d < x[i]-'0'){d = x[i] - '0';}
    lint nax = binary_search(d);
    cout << nax - d << endl;
    return 0;
}

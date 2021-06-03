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

lint modpow(lint x, lint n) {
    lint ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

lint digsum(lint n){
    lint res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    lint a = modpow(2, 1000);
    cout << digsum(a) << endl;
    return 0;
}

#include <bits/stdc++.h>
#include <random>
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

int main(){
    random_device gen;
    mt19937_64 engine(gen());
    int n, m;
    cin >> n >> m;
    ofstream out("out.in");
    out << n << ' ' << m << "\n";
    rep(i,m){
        int a = engine() % n + 1;
        int b = engine() % n + 1;
        if(a > b)swap(a, b);
        out << a << ' ' << b << "\n";
    }
    out << 17 << "\n";
    REP(i,17)out << i << ' ';
    out << "\n";
    return 0;
}

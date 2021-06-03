#include <bits/stdc++.h>
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

int main(){
    ll n;
    cin >> n;
    vector<lp> pf = prime_factor(n);
    ll ans = 1;
    for(auto x:pf){
        if(x.first % 2 == 1)ans *= (x.second+1);
    }
    cout << ans*2 << endl;
    return 0;
}

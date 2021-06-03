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

template <typename T>
struct primefactor{
    vector<T> spf;
    primefactor(T n){ init(n); }
    void init(T n){
        spf.assign(n+1, 0);
        for(T i = 0; i <= n; ++i)spf[i] = i;
        for(T i = 2; i*i <= n; ++i){
            if(spf[i] == i){
                for(T j = i*i; j <= n; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n){
        map<T, T> m;
        while(n != 1){
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};


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
    ll sum = 0;
    REP(ad, n){
        sum += ad;
        vector<lp> facts = prime_factor(sum);
        ll t = 1;
        for(auto x:facts){
            t *= (x.second + 1);
        }
        if(t > 500){
            cout << sum << endl;
            return 0;
        }
    }
    return 0;
}

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
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int PRIMES_MAX = 10000000;
vector<int> min_primefactor(PRIMES_MAX, inf);

void init_min_primefactor(){
    min_primefactor[0] = 0;
    min_primefactor[1] = 1;
    for(int i = 2; i < PRIMES_MAX; ++i){
        if(min_primefactor[i] == inf){
            for(int k = 1; i * k < PRIMES_MAX; ++k){
                min_primefactor[i * k] = i;
            }
        }
    }
}

map<int,int> prime_factor(int N){
    map<int, int> res;
    while(N > 1){
        res[min_primefactor[N]]++;
        N /= min_primefactor[N];
    }
    return res;
}

int main(){
    int a;
    cin >> a;
    ll ans = 1;
    map<int, int> pr;
    init_min_primefactor();
    for(ll i = a; i > 1; --i){
        map<int,int> k = prime_factor(i);
        for(auto x:k){
            pr[x.first] = max(pr[x.first], x.second);
        }
    }
    for(auto x:pr){
        ans *= pow(x.first, x.second);
    }
    cout << ans+1 << endl;
    return 0;
}

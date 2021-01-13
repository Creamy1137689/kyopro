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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int cnt = 0;
    for(ll i = 1; ; ++i){
        for(ll j = 1; j < i; ++j){
            ll a = i*i - j*j;
            ll b = 2*i*j;
            ll c = i*i + j*j;
            if(a > b)swap(a, b);
            if(gcd(gcd(a, b), c) == 1){cout << a << ' ' << b << ' ' << c << endl; ++cnt;}
            if(cnt == 4){
                return 0;
            }
        }
    }
    return 0;
}

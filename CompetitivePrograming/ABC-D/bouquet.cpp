#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

ll rep_power_modM(ll a, ll n, ll M){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
    int n,a,b; cin>>n>>a>>b;
    ll ans = rep_power_modM(2,n,MOD)-1;
    ll comb_a = 1; rep(i,a){comb_a *= (n-i)%MOD; comb_a%=MOD;}
    ll comb_b = 1; rep(i,b){comb_b *= (n-i)%MOD; comb_b%=MOD;}

    ll divisor_a = 1; rep(i,a){divisor_a *= (i+1)%MOD; divisor_a %=MOD;}
    ll divisor_b = 1; rep(i,b){divisor_b *= (i+1)%MOD; divisor_b %=MOD;}

    comb_a = comb_a * rep_power_modM(divisor_a,MOD-2,MOD)%MOD;
    comb_b = comb_b * rep_power_modM(divisor_b,MOD-2,MOD)%MOD;
    ans -= comb_a; if(ans<0)ans+=MOD;
    ans -= comb_b; if(ans<0)ans+=MOD;

    cout<< ans <<endl;return 0;
}

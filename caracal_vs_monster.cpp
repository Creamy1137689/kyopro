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
#define REP(i,n) for(int i = 1; i<n; ++i)
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

//繰り返しn乗法……aをn乗したもののMOD(M)をとる
ll rep_power_modM(ll a, ll n, ll M){
    if(n == 0)return 1;
    if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
    return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
    ll h; cin>>h;
    int count = 0;
    while(h>1){++count; h /= 2;}
    ll ans = 0;
    for(; count>=0; --count){
        ans += rep_power_modM(2,count,INF);
    }
    cout<<ans<<endl; return 0;
}

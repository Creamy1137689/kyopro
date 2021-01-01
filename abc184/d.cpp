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

long double memo[105][105][105];

long double dp(long double a, long double b, long double c){
    if(memo[(int)a][(int)b][(int)c] != inf)return memo[(int)a][(int)b][(int)c];
    if(a == 100 || b == 100 || c == 100)return 0;
    long double res = 1;
    res += dp(a+1, b, c) * a/(a+b+c);
    res += dp(a, b+1, c) * b/(a+b+c);
    res += dp(a, b, c+1) * c/(a+b+c);
    return memo[(int)a][(int)b][(int)c] = res;
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    rep(i,105)rep(j,105)rep(k,105)memo[i][j][k] = inf;
    cout << fixed << setprecision(10) << dp(a, b, c) << endl;
    return 0;
}

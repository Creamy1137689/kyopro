#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<' ';
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n; cin>>n;
    const double RATE = 380000.0;
    vector<string> u(n);
    vector<double> x(n);
    rep(i,n)cin>>x[i]>>u[i];
    double long ans = 0;
    rep(i,n){
        if(u[i] == "BTC")ans += x[i]*RATE;
        else ans += x[i];
    }
    cout<<fixed<<setprecision(10)<<ans<<endl; return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#define all(x) begin(x),end(x)
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
    vint rs(n); rep(i,n)cin>>rs[i];
    sort(all(rs));
    int rd = 1; if(n%2==0)rd = 0;
    double ans = rs[n-1]*rs[n-1];
    if(!rd)ans -= rs[0]*rs[0];
    for(int i = 1; i<n-1; i++){
        if(i%2 == rd)ans -= (rs[i]*rs[i]-rs[i-1]*rs[i-1]);
    }
    cout<<fixed<<setprecision(10)<<ans*M_PI<<endl;
}

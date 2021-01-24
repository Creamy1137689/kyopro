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
    ll n, k;
    cin >> n >> k;
    if(k <= n)
        cout << k*k*k << endl;
    else if(k <= 2*n)
        cout << k*k*k - 3*(k-n)*(k-n)*(k-n) << endl;
    else if(k <= 3*n)
        cout << 6*n*n*n - (3*n-k)*(3*n-k)*(3*n-k) << endl;
    else
        cout << 6*n*n*n << endl;
    return 0;
}

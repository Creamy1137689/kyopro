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

int main(){
    int n,k; cin>>n>>k;

    vector<ll> hp(n);rep(i,n)cin>>hp[i];
    sort(hp.begin(),hp.end());
    
    ll ans = 0;
    rep(i,n-k)ans += hp[i];
    cout<<ans<<endl;return 0;
}

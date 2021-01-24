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

int gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector <ll> array(n); rep(i,n)cin>>array[i];
    vector <ll> lgcd(n+1,0); rep(i,n) lgcd[i+1] = gcd(lgcd[i], array[i]);
    vector <ll> rgcd(n+1,0); rep(i,n) rgcd[i+1] = gcd(rgcd[i], array[n-i-1]);
    //for(auto x : lgcd) cout << x << endl;
    ll ans = -INF;
    for(int i = 1; i <= n; ++i){
        ll tmp_gcd = gcd(lgcd[i-1], rgcd[n-i]);
        ans = max(ans, tmp_gcd);
    }
    cout << ans << endl; return 0;
}

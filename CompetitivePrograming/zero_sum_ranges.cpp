#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int n; cin >> n; map <ll, ll> mp;
    ll sum = 0;mp[sum] = 1;
    for(int i = 0; i<n; ++i) {
        ll tmp; cin >> tmp;
        sum += tmp;
        if(mp.count(sum)) ++mp[sum];
        else mp[sum] = 1;
    }
    ll ans = 0;
    for(auto x : mp){
        if(x.second != 1)ans += x.second*(x.second-1)/2;
    }
    cout << ans << endl; return 0;
}
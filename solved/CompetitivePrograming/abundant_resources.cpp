#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector <ll> a(n); rep(i,n)cin >> a[i];
    vector <ll> s(n+1,0); rep(i,n) s[i+1] = s[i] + a[i];
    for(int i = 1; i<= n; ++i){
        ll ans = -INF;
        for(int j = 0; j+i<=n; ++j){
            ans = max(ans, s[j+i] - s[j]);
        }
        cout << ans << endl;
    }
}

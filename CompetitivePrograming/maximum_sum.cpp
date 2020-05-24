#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;

typedef long long ll;

int main(){
    int n, k; cin >> n >> k;
    vector <int> sum(n+1,0);
    for(int i = 1; i<=n; ++i){
        int tmp; cin >> tmp; sum[i] = sum[i-1] + tmp;
    }
    ll ans = 0;
    for(int i = 0; i+k<=n; ++i){
        ll tmp = sum[i+k] - sum[i]; ans = max(ans,tmp);
    }
    cout << ans << endl; return 0;
}
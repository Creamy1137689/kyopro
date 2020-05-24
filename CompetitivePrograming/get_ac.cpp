#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    int l[n], r[n]; for(int i = 0; i<q; ++i)cin >> l[i] >> r[i];
    vector <int> exsist(n,0);
    for(int i = 1; i<n; ++i) if(s[i-1] == 'A' && s[i] == 'C')exsist[i] = 1;
    vector <int> sum(n+1,0);
    for(int i = 0; i<n; ++i) sum[i+1] = sum[i] + exsist[i];
    cout << endl;
    for(int i = 0; i<q; ++i){
        cout << sum[r[i]] - sum[l[i]] <<endl;
    }
    return 0;
}
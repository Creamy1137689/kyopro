#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define rep(i,n) for(int i = 0; i<n; ++i)

int main(){
    int n; cin >> n;
    vector<vector<ll> > machine(n, vector<ll>(n));
    rep(i,n)rep(j,n)cin >> machine[i][j];

    vector<vector<ll>> sum(n+1, vector<ll>(n+1,0));
    rep(i,n)rep(j,n) sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] +machine[i][j];

    vector<ll> vals(n*n+1,0);
    for(int x1 = 0; x1<n; ++x1){
        for(int y1 = 0; y1<n; ++y1){
            for(int x2 = x1+1; x2<=n; ++x2){
                for(int y2 = y1+1; y2<=n; ++y2){
                    ll area = (x2-x1)*(y2-y1);
                    ll s = sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1];
                    vals[area] = max(vals[area],s);
                }
            }
        }
    }

    rep(i,n*n)vals[i+1] = max(vals[i], vals[i+1]);

    int q; cin >> q; vector<int> query(q,0);
    rep(i,q)cin >> query[i];
    rep(i,q){
        cout << vals[query[i]] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> nap(13, vector<char>(13,'.'));
    REP(i,h)REP(j,w)cin >> nap[i][j];
    int n = 0;
    rep(i, h)rep(j,w){
        int dcnt = 0;
        if(nap[i][j] == '.')++dcnt;
        if(nap[i+1][j] == '.')++dcnt;
        if(nap[i][j+1] == '.')++dcnt;
        if(nap[i+1][j+1] == '.')++dcnt;
        if(dcnt == 1 || dcnt == 3)++n;
    }
    cout << n << endl;
    return 0;
}

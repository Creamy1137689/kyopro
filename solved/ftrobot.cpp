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
    string s;
    int x, y;
    cin >> s >> x >> y;
    x += 10000; y += 10000;
    int n = s.size();
    vector<int> vert, hol;
    s += 'T';
    int cnt = 0;
    int tcnt = 0;
    int fir = 0;
    rep(i,n+1){
        if(s[i] == 'T'){
            if(tcnt % 2 == 0){
                if(tcnt == 0){
                    fir = cnt;
                }else if(cnt!=0)hol.emplace_back(cnt);
            }else{
                if(cnt!=0)vert.emplace_back(cnt);
            }
            ++tcnt;
            cnt = 0;
        }else{
            ++cnt;
        }
    }
    vector<vector<bool>> vertdp(vert.size()+1, vector<bool>(20000, false));
    vector<vector<bool>> holdp(hol.size()+1, vector<bool>(20000, false));
    vertdp[0][10000] = true;
    holdp[0][10000] = true;
    holdp[0][fir + 10000] = true;
    rep(i,hol.size()){
        rep(j,20000){
            if(holdp[i][j]){
                holdp[i+1][j-hol[i]] = true;
                holdp[i+1][j+hol[i]] = true;
            }
        }
    }
    rep(i,vert.size()){
        rep(j,20000){
            if(vertdp[i][j]){
                vertdp[i+1][j-vert[i]] = true;
                vertdp[i+1][j+vert[i]] = true;
            }
        }
    }
    cout << ((holdp[hol.size()][x] && vertdp[vert.size()][y]) ? "Yes" : "No") << endl;
    return 0;
}

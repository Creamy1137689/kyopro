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
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

char in[1010][1010];
char pat[2][2];

bool check(int s, int t){
    bool res = true;
    rep(i,2)rep(j,2)if(in[s+i][t+j] != pat[i][j])res = false;
    return res;
}

int dif(int s, int t, char c){
    int res = 0;
    rep(i,2)rep(j,2)if(check(s-i, t-j))--res;
    char bf = in[s][t];
    in[s][t] = c;
    rep(i,2)rep(j,2)if(check(s-i, t-j))++res;
    in[s][t] = bf;
    return res;
}

int main(){
    int H, W;
    char cand[3] = {'J', 'O', 'I'};
    cin >> H >> W;
    REP(i,H)REP(j,W)cin >> in[i][j];
    rep(i,2)rep(j,2)cin >> pat[i][j];
    int inicnt = 0;
    REP(i,H)REP(j,W)if(check(i,j))++inicnt;
    int ans = inicnt;
    REP(i,H)REP(j,W){
        rep(k,3){
            ans = max(ans, inicnt + dif(i,j,cand[k]));
        }
    }
    cout << ans << endl;
    return 0;
}

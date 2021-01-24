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

int main(){
    int H,W;
    cin >> H >> W;
    vector nap(H, vector<char>(W));
    vector ocnt(H, vector<int>(W+1, 0));
    vector icnt(H+1, vector<int>(W, 0));
    rep(i,H)rep(j,W)cin >> nap[i][j];
    rep(i,H){
        for(int j = W-1; j >= 0; --j){
            ocnt[i][j] = ocnt[i][j+1] + (nap[i][j] == 'O');
        }
    }
    rep(j,W){
        for(int i = H-1; i >= 0; --i){
            icnt[i][j] = icnt[i+1][j] + (nap[i][j] == 'I');
        }
    }
    ll ans = 0;
    rep(i,H)rep(j,W){
        if(nap[i][j] == 'J')ans += ocnt[i][j] * icnt[i][j];
    }
    cout << ans << endl;
    return 0;
}

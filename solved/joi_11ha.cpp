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
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> nap(H, vector<char>(W));
    vector<vector<int>> sum_j(H+1, vector<int>(W+1, 0));
    vector<vector<int>> sum_o(H+1, vector<int>(W+1, 0));
    vector<vector<int>> sum_i(H+1, vector<int>(W+1, 0));
    rep(i,H)rep(j,W)cin >> nap[i][j];
    REP(i,H)REP(j,W)sum_j[i][j] = sum_j[i-1][j] + sum_j[i][j-1] - sum_j[i-1][j-1] + (nap[i-1][j-1] == 'J');
    REP(i,H)REP(j,W)sum_o[i][j] = sum_o[i-1][j] + sum_o[i][j-1] - sum_o[i-1][j-1] + (nap[i-1][j-1] == 'O');
    REP(i,H)REP(j,W)sum_i[i][j] = sum_i[i-1][j] + sum_i[i][j-1] - sum_i[i-1][j-1] + (nap[i-1][j-1] == 'I');
    int lx, ly, rx, ry;
    rep(i,K){
        cin >> ly >> lx >> ry >> rx;
        --ly, --lx;
        int res_j = sum_j[ry][rx] + sum_j[ly][lx] - sum_j[ry][lx] - sum_j[ly][rx];
        int res_o = sum_o[ry][rx] + sum_o[ly][lx] - sum_o[ry][lx] - sum_o[ly][rx];
        int res_i = sum_i[ry][rx] + sum_i[ly][lx] - sum_i[ry][lx] - sum_i[ly][rx];
        cout << res_j << ' ' << res_o << ' ' << res_i << endl;
    }
    return 0;
}

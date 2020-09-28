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
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int dy[2] = {1,0}, dx[2] = {0,1};
    int H, W;
    cin >> H >> W;
    vector<vector<char>> nap(1010, vector<char>(1010));
    vector<vector<ll>> ans(1010, vector<ll>(1010, 0));
    vector<vector<bool>> al(1010, vector<bool>(1010, false));
    REP(i,H)REP(j,W){cin >> nap[i][j];}
    queue<P> Q;
    Q.emplace(1,1);
    ans[1][1] = 1;
    while(!Q.empty()){
        int y = Q.front().first, x = Q.front().second;
        Q.pop();
        if(al[y][x])continue;
        al[y][x] = true;
        rep(i,2){
            int ny = dy[i] + y, nx = dx[i] + x;
            if(nap[ny][nx] == '.'){
                ans[ny][nx] += ans[y][x];
                ans[ny][nx] %= MOD;
                Q.emplace(ny, nx);
            }
        }
    }
    cout << ans[H][W] << endl;
    return 0;
}

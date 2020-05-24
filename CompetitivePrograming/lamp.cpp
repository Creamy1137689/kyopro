#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    int H,W; cin >> H >> W;
    char maze[H][W]; rep(i,H)rep(j,W)cin >> maze[i][j];
    //Right
    int R[H][W] = {}; rep(i,H)if(maze[i][W-1] == '#') R[i][W-1] = 0; else R[i][W-1] = 1;
    for(int i = 0; i<H; ++i){
        for(int j = W-2; j>=0; --j){
            if(maze[i][j] == '#')R[i][j] =0;
            else if(maze[i][j+1] == '#')R[i][j] = 1;
            else R[i][j] = R[i][j+1] + 1;
        }
    }
    //Left
    int L[H][W] = {}; rep(i,H)if(maze[i][0] == '#') L[i][0] = 0; else L[i][0] = 1;
    for(int i = 0; i<H; ++i){
        for(int j = 1; j<W; ++j){
            if(maze[i][j] == '#')L[i][j] =0;
            else if(maze[i][j-1] == '#')L[i][j] = 1;
            else L[i][j] = L[i][j-1] + 1;
        }
    }
    //Up
    int U[H][W] = {}; rep(i,W)if(maze[0][i] == '#') U[0][i] = 0; else U[0][i] = 1;
    for(int i = 0; i<W; ++i){
        for(int j = 1; j<H; ++j){
            if(maze[j][i] == '#')U[j][i] =0;
            else if(maze[j-1][i] == '#')U[j][i] = 1;
            else U[j][i] = U[j-1][i] + 1;
        }
    }
    //Down
    int D[H][W] = {}; rep(i,W)if(maze[H-1][i] == '#') D[H-1][i] = 0; else D[H-1][i] = 1;
    for(int i = 0; i<W; ++i){
        for(int j = H-2; j>=0; --j){
            if(maze[j][i] == '#')D[j][i] =0;
            else if(maze[j+1][i] == '#')D[j][i] = 1;
            else D[j][i] = D[j+1][i] + 1;
        }
    }
    int ans = -INF;
    rep(i,H)rep(j,W){
        ans = max(ans, D[i][j] + U[i][j] + R[i][j] + L[i][j] -3);
    }
    cout << ans << endl;
}

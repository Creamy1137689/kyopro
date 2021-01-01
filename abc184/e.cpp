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

int ddx[4] = {0,1,0,-1};
int ddy[4] = {1,0,-1,0};

struct str{
    int first, second, cost;
};

int main(){
    char nap[2020][2020];
    vector<vector<int>> ans(2020, vector<int>(2020, inf));
    vector<queue<P>> telep(26, queue<P>()) ;
    int H, W;
    P s,g;
    cin >> H >> W;
    REP(i,H)REP(j,W){
        cin >> nap[i][j];
        if(nap[i][j] == 'S')s = make_pair(i,j);
        if(nap[i][j] == 'G')g = make_pair(i,j);
        if('a' <= nap[i][j] && nap[i][j] <= 'z')telep[nap[i][j]-'a'].push(make_pair(i,j));
    }
    //REP(i,H)REP(j,W){
    //    if(i == 1 && j == 1)nap[i][j] = 'S';
    //    else if(i == H && j == W)nap[i][j] = 'G';
    //    else nap[i][j] = 'a';
    //    if(nap[i][j] == 'S')s = make_pair(i,j);
    //    if(nap[i][j] == 'G')g = make_pair(i,j);
    //    if('a' <= nap[i][j] && nap[i][j] <= 'z')telep[nap[i][j]-'a'].push(make_pair(i,j));
    //}
    queue<str> q;
    ans[s.first][s.second] = 0;
    q.push({s.first, s.second, 0});
    while(!q.empty()){
        int y = q.front().first, x = q.front().second, ct = q.front().cost;
        q.pop();
        if(ct > ans[y][x])continue;
        ans[y][x] = ct;
        //printf("[y,x] -> [%d, %d], cost ->[%d]\n", y, x, ans[y][x]);
        if('a' <= nap[y][x] && nap[y][x] <= 'z'){
            int c = nap[y][x] - 'a';
            while(!telep[c].empty()){
                P t = telep[c].front();
                telep[c].pop();
                if(t == make_pair(y, x))continue;
                if(ans[t.first][t.second] == inf){
                    q.push({t.first, t.second, ans[y][x]+1});
                    ans[t.first][t.second] = min(ans[t.first][t.second], ans[y][x] + 1);
                }
            }
        }
        rep(i,4){
            int dy = ddy[i] + y, dx = ddx[i] + x;
            if(ans[dy][dx] == inf && (nap[dy][dx] == '.' || ('a' <= nap[dy][dx] && nap[dy][dx] <= 'z') || nap[dy][dx] == 'G')){
                q.push({dy, dx, ans[y][x]+1});
                ans[dy][dx] = min(ans[dy][dx], ans[y][x] + 1);
            }
        }
    }
    int res = ans[g.first][g.second];
    if(res == inf)res = -1;
    cout << res << endl;
    return 0;
}

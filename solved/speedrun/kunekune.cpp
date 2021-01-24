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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<vector<char>> mp(2020, vector<char>(2020, '#'));
vector<vector<P>> ans(2020, vector<P>(2020, make_pair(inf, inf)));

int ddy[4] = {1, 0, -1, 0};
int ddx[4] = {0, 1, 0, -1};

int main(){
    int h, w;
    cin >> h >> w;
    P s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    REP(i,h)REP(j,w)cin >> mp[i][j];
    queue<P> q;
    q.push(s);
    ans[s.first][s.second].first = 0;
    ans[s.first][s.second].second = 0;
    while(!q.empty()){
        P n = q.front();
        q.pop();
        rep(i,4){
            P t = n;
            t.first += ddy[i];
            t.second += ddx[i];
            if(mp[t.first][t.second] == '#')continue;
            bool ok = false;
            if(i % 2 == 0){
                if(ans[t.first][t.second].first == inf && ans[n.first][n.second].second != inf){
                    ans[t.first][t.second].first = ans[n.first][n.second].second + 1;
                    ok = true;
                }
            }else{
                if(ans[t.first][t.second].second == inf && ans[n.first][n.second].first != inf){
                    ans[t.first][t.second].second = ans[n.first][n.second].first + 1;
                    ok = true;
                }
            }
            if(ok)q.push(t);
        }
    }
    int res = inf;
    res = min({res, ans[g.first][g.second].first, ans[g.first][g.second].second});
    if(res == inf)res = -1;
    cout << res << endl;
    return 0;
}

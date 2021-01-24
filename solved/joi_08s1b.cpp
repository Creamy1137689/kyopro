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
#define show(obj) {for(auto x:obj)cout<<x<<' ';}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

struct sq{
    int x1 = inf, x2 = -inf, y1 = inf, y2 = -inf;
};

void topological_sort(int s, vector<int> &sorted, vector<bool> &visited, vector<vector<int>> &G){
    if(G[s].size() == 0){sorted.push_back(s+1); return ;}
    for(auto x:G[s]){
        if(!visited[x]){
            visited[x] = true;
            topological_sort(x, sorted, visited, G);
        }
    }
    sorted.push_back(s+1);
}

int main(){
    int N, H, W, c;
    cin >> N >> H >> W;
    vector<sq> sheet(N);
    vector<vector<int>> nap(H, vector<int>(W));
    rep(i,H){
        rep(j,W){
            cin >> c;
            nap[i][j] = c;
            if(c == 0)continue;
            --c;
            chmin(sheet[c].x1, j);
            chmax(sheet[c].x2, j);
            chmin(sheet[c].y1, i);
            chmax(sheet[c].y2, i);
        }
    } 
    vector<vector<int>> G(N, vector<int>());
    vector<bool> canuse(N, false);
    rep(i,N){
        int x1 = sheet[i].x1;
        int x2 = sheet[i].x2;
        int y1 = sheet[i].y1;
        int y2 = sheet[i].y2;
        if(x1 == inf)continue;
        canuse[i] = true;
        for(int y = y1; y <= y2; ++y){
            for(int x = x1; x <= x2; ++x){
                int k = nap[y][x];
                if(k != 0 && k != (i+1))G[k-1].push_back(i);
            }
        }
    }
    vector<int> ans;
    vector<bool> used(N, false);
    rep(i,N){
        if(!used[i] & canuse[i]){
            used[i] = true;
            topological_sort(i, ans, used, G);
        }
    }
    rep(i,N)if(!used[i])cout << i+1 << ' ';
    rep(i,ans.size()){
        cout << ans[i];
        if(i < ans.size()-1)cout << ' ';
    }
    cout << endl;
    return 0;
}

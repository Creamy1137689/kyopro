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

struct det{
    int x1, y1, x2, y2, x3, y3;
};

det none = {inf, inf, inf, inf, inf, inf};

det op(int y, int x, vector<vector<char>> &nap){
    vector<P> pos;
    rep(dy, 2)rep(dx, 2){
        if(nap[y + dy][x + dx] == '1')pos.push_back(make_pair(dy, dx));
    }
    if(pos.size() == 0)return none;
    else if(pos.size() == 4){
        rep(i,3){
            nap[y+pos[i].first][x+pos[i].second] = (nap[y+pos[i].first][x+pos[i].second] == '1' ? '0' : '1');
        }
        return {y+pos[0].first, x+pos[0].second, y+pos[1].first, x+pos[1].second, y+pos[2].first, x+pos[2].second};
    }
    else{
        rep(dy, 2)rep(dx, 2){
            if(pos.size() < 4 && (dy != pos[0].first || dx != pos[0].second))pos.push_back(make_pair(dy, dx));
        }
        rep(i,3){
            nap[y+pos[i].first][x+pos[i].second] = (nap[y+pos[i].first][x+pos[i].second] == '1' ? '0' : '1');
        }
        return {y+pos[0].first, x+pos[0].second, y+pos[1].first, x+pos[1].second, y+pos[2].first, x+pos[2].second};
    } 
}

int solve(int N, int M, vector<vector<char>> nap){
    vector<det> ans;
    rep(i,N-1)rep(j,M-1){
        while(true){
            det t = op(i,j, nap);
            if(t.x1 == inf)break;
            else ans.push_back(t);
        }
    }    
    cout << ans.size() << endl;
    for(auto x:ans){
        printf("%d %d %d %d %d %d\n", x.x1+1 , x.y1+1, x.x2+1, x.y2+1, x.x3+1, x.y3+1);
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    vector<P> nm(T);
    vector<vector<vector<char>>> input(T);
    rep(i,T){
        cin >> nm[i].first >> nm[i].second;
        input[i] = vector<vector<char>>(nm[i].first, vector<char>(nm[i].second));
        rep(j,nm[i].first)rep(k,nm[i].second)cin >> input[i][j][k];
    }
    rep(i,T)solve(nm[i].first, nm[i].second, input[i]);
    return 0;
}

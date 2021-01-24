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

void replace(det d, vector<vector<char>> &nap){
    nap[d.y1][d.x1] = (nap[d.y1][d.x1] == '1' ? '0' : '1');
    nap[d.y2][d.x2] = (nap[d.y2][d.x2] == '1' ? '0' : '1');
    nap[d.y3][d.x3] = (nap[d.y3][d.x3] == '1' ? '0' : '1');
}

int solve(int N, int M, vector<vector<char>> nap){
    vector<det> ans;
    rep(i,N-1)rep(j,M-1){
        if(nap[i][j] == '1'){
            ans.push_back({j, i, j+1, i, j+1, i+1});
            replace({j, i, j+1, i, j+1, i+1}, nap);
        }
    }
    rep(i,N-1){
        if(nap[i][M-1] == '1' && nap[i+1][M-1] == '1'){
            ans.push_back({M-2, i, M-2, i+1, M-1, i+1});
            ans.push_back({M-2, i, M-2, i+1, M-1, i});
            replace({M-2, i, M-2, i+1, M-1, i+1},nap);
            replace({M-2, i, M-2, i+1, M-1, i},nap);
        }else if(nap[i][M-1] == '1'){
            ans.push_back({M-2, i, M-2, i+1, M-1, i});
            ans.push_back({M-2, i, M-1, i  , M-1, i+1});
            ans.push_back({M-1, i+1, M-2, i+1, M-1, i});
            replace({M-2, i, M-2, i+1, M-1, i}, nap);
            replace({M-2, i, M-1, i, M-1, i+1}, nap);
            replace({M-1, i+1, M-2, i+1, M-1, i}, nap);
        }
    }
    rep(j,M-1){
        if(nap[N-1][j] == '1' && nap[N-1][j+1] == '1'){
            ans.push_back({j, N-2, j+1, N-2, j+1, N-1});
            ans.push_back({j, N-1, j, N-2, j+1, N-2});
            replace({j, N-2, j+1, N-2, j+1, N-1}, nap);
            replace({j, N-1, j, N-2, j+1, N-2}, nap);
        }else if(nap[N-1][j] == '1'){
            ans.push_back({j+1, N-2, j+1, N-1, j, N-1});
            ans.push_back({j, N-1, j, N-2, j+1, N-2});
            ans.push_back({j+1, N-1, j, N-1, j, N-2});
            replace({j+1, N-2, j+1, N-1, j, N-1}, nap);
            replace({j, N-1, j, N-2, j+1, N-2}, nap);
            replace({j+1, N-1, j, N-1, j, N-2}, nap);
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


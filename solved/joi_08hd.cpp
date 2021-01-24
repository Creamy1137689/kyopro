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

int dp[155][1010][77];

template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int N, M, k, p, s;
    cin >> N >> M;
    vector<vector<P>> stone(N, vector<P>());
    rep(i,N){
        cin >> k;
        while(k-- > 0){
            cin >> p >> s;
            stone[i].push_back(make_pair(p-1, s));
        }
    }
    rep(i,155)rep(j,1010)rep(k, 77){
        dp[i][j][k] = inf;
    }
    rep(i,stone[0].size()){
        dp[0][stone[0][i].first][0] = 0;
    }
    rep(i,stone[1].size()){
        dp[1][stone[1][i].first][1] = 0;
    }
    rep(i, N-1)rep(j, stone[i].size())rep(k,77){
        int f = stone[i][j].first;
        int base_slip = stone[i][j].second;
        rep(l, stone[i+1].size()){
            int t = stone[i+1][l].first;
            int to_slip = stone[i+1][l].second;
            chmin(dp[i+1][t][k], dp[i][f][k] + (base_slip + to_slip)*abs(f - t));
            //if(k == 0)printf("[(%d, %d) -> (%d, %d)][value = %d]\n", i, f, i+1, t, dp[i+1][t][k]);
        }
        if(i < N-2){
            rep(l, stone[i+2].size()){
                int t = stone[i+2][l].first;
                int to_slip = stone[i+2][l].second;
                chmin(dp[i+2][t][k+1], dp[i][f][k] + (base_slip + to_slip)*abs(f - t));
            }
            //if(k == 0){cout << line << endl; rep(x,N){rep(y,4)printf(" %2d ", (dp[x][y][0] == inf ? -1 : dp[x][y][0])); cout << endl;}}
        }
    }
    int ans = inf;
    rep(j,1010)rep(k,M+1)chmin(ans, dp[N-1][j][k]);
    rep(j,1010)rep(k,M)chmin(ans, dp[N-2][j][k]);
    cout << ans << endl;
    return 0;
}

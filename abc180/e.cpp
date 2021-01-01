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

int N;

struct datum{
    ll x, y, z;
};

int graph[20][20];

int dp[(1<<20) + 1][21]; 
int rec(int bit, int v){
    if (dp[bit][v] != -1) return dp[bit][v];
    if (bit == (1<<v)) {
        return dp[bit][v] = 0;
    }
    int res = inf;
    int prev_bit = bit & ~(1<<v);
    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1<<u))) continue; 
        if (res > rec(prev_bit, u) + graph[u][v]) {
            res = rec(prev_bit, u) + graph[u][v];
        }
    }

    return dp[bit][v] = res; 
}

int main(){
    cin >> N;
    vector<datum> input(N);
    rep(i,N)cin >> input[i].x >> input[i].y >> input[i].z;
    rep(i,N)rep(j,N){
        if(i == j)continue;
        graph[i][j] = abs(input[j].x - input[i].x) + abs(input[j].y - input[i].y) + max(0LL, input[j].z - input[i].z);
    }
    //rep(i,N){rep(j,N)cout << graph[i][j] << ' '; cout << endl;}
    for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = inf;
    //int ans = inf;
    //for (int v = 1; v < N; ++v) {
    //    if (ans > rec((1<<N)-1, v)) {
    //        ans = rec((1<<N)-1, v) + graph[v][0];
    //    }
    //}
    dp[0][0] = 0;
    for(int S = 1; S<(1<<N); ++S){
        for(int v = 0; v < N; ++v){
            if(S & (1<<v)){
                for(int j = 0; j < N; ++j){
                    dp[S][v] = min(dp[S][v], dp[S-(1<<v)][j] + graph[j][v]);
                }
            }
        }
    }
    cout << dp[(1<<N)-1][0] << endl;
    return 0;
}

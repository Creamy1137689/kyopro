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

vector<int> memo(200000, -inf);
vector<vector<int>> G(200000, vector<int>());
vector<int> power(200000, -inf);

int dfs(int f){
    int res = power[f];
    for(auto x:G[f]){
        int k = dfs(x);
        if(k > 0)res += k;
    }
    return memo[f] = res;
}

int main(){
    int N, a, s; 
    cin >> N;
    REP(i,N){
        cin >> s >> a;
        power[i] = a;
        G[s].push_back(i);
    }
    dfs(0);
    int ans = -inf;
    rep(i,N+1)ans = max(ans, memo[i]);
    cout << ans << endl;
    return 0;
}

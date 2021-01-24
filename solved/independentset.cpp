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

vector<vector<int>> G(100000, vector<int>());
vector<bool> vis(100000, false);

lp solve(int nod){
    vis[nod] = true;
    if((G[nod].size() == 1 && vis[G[nod][0]]) || G[nod].size() == 0){
        return make_pair(1, 1);
    }
    lp res = make_pair(1, 1);
    for(auto x:G[nod]){
        if(!vis[x]){
            lp t = solve(x);
            res.first *= t.first + t.second;
            res.second *= t.first;
            res.first %= MOD;
            res.second %= MOD;
        }
    }
    return res;
}

int main(){
    int n, a, b;
    cin >> n;
    G.resize(n);
    vis.resize(n);
    rep(i,n-1){
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    lp ans = solve(0);
    cout << (ans.first + ans.second) % MOD << endl;
    return 0;
}

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

int N, M, a, b, c;
vector<vector<P>> G(101000);

void dfs(int from,  vector<int> &ans){
    for(auto to:G[from]){
        if(ans[to.first] == inf){
            int c = to.second;
            if(ans[from] == c){
                ans[to.first] = (c == 1 ? N : 1);
            }else{
                ans[to.first] = c;
            }
            dfs(to.first, ans);
        }
    }
}

int main(){
    int st = 0;
    cin >> N >> M;
    G.resize(N);
    rep(i,M){
        cin >> a >> b >> c;
        --a; --b;
        if(a == 0 || b == 0)st = c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    vector<int> ans(N, inf);
    ans[0] = st;
    dfs(0, ans);
    rep(i,N)cout << ans[i] << endl;
    return 0;
}

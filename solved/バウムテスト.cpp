#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int MAX_V = 110;
vector<vector<int>> G(MAX_V, vector<int>());
vector<bool> al(MAX_V,false);

bool dfs(int v,int from){
    if(al[v])return false;
    al[v] = true;
    rep(i,G[v].size()){
        if(G[v][i] == from)continue;
        if(dfs(G[v][i],v)); else return false;
    }
    return true;
}

int main(){
    int V,E;cin>>V>>E;
    rep(i,E){
        int f,t; cin>>f>>t;
        G[--f].push_back(--t);
        G[t].push_back(f);
    }
    int ans = 0;
    rep(i,V){
        if(!al[i]){
            if(dfs(i,inf))ans++;
        }
    }
    cout<<ans<<endl; return 0;
}

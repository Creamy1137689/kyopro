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

void topological_sort(int s, vector<int> &sorted, vector<bool> &visited, vector<vector<int>> &G){
    if(G[s].size() == 0){sorted.push_back(s); return ;}
    for(auto x:G[s]){
        if(!visited[x]){
            visited[x] = true;
            topological_sort(x, sorted, visited, G);
        }
    }
    sorted.push_back(s);
}

int main(){
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    rep(i,M){
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
    }
    vector<int> sorted;
    vector<bool> visited(N, false);
    rep(i,N){
        if(!visited[i]){
            visited[i] = true;
            topological_sort(i, sorted, visited, G);
        }
    }
    reverse(all(sorted));
    bool exist = false;
    rep(i,N-1){
        int s = sorted[i], t = sorted[i+1];
        bool ok = false;
        for(auto x:G[s]){
            if(x == t)ok = true;
        }
        if(!ok)exist = true;
    }
    rep(i,N)cout << sorted[i] +1 << endl;
    cout << exist << endl;
    return 0;
}

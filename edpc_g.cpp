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
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int main(){
    int N, M, x, y;
    cin >> N >> M;
    vector<int> in(N,0);
    vector<vector<int>> G(N, vector<int>());
    vector<int> dist(N, -1);
    rep(i,M){
        cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
        ++in[y];
    }
    queue<int> Q;
    rep(i,N)if(in[i] == 0){Q.push(i); dist[i] = 0;}
    while(!Q.empty()){
        int f = Q.front();
        Q.pop();
        for(auto t:G[f]){
            --in[t];
            if(in[t] == 0)Q.push(t);
            chmax(dist[t], dist[f] + 1);            
        }
    }
    int ans = 0;
    rep(i,N)chmax(ans, dist[i]);
    cout << ans << endl;
    return 0;
}

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

ll N, T, Q;
vector<ll> pos(5000000);
vector<ll> dir(5000000);

void dfs(vector<ll> &ans, ll mid, ll ind){
    if(ind == 0 || ind == N-1)return ;    
    if(dir[ind] == 1 && dir[ind-1] == 1){
        ll dif = abs(mid - pos[ind-1]);
        if(dif < T){
            ans[ind-1] = mid;
            dfs(ans, mid, ind-1);
        }
    }
    if(dir[ind] == 2 && dir[ind+1] == 2){
        ll dif = abs(mid - pos[ind+1]);
        if(dif < T){
            ans[ind+1] = mid;
            dfs(ans, mid, ind+1);
        }
    }
    return ;
}

ll d(ll dir){return (dir == 1 ? 1 : -1);}

int main(){
    cin >> N >> T >> Q;
    vector<ll> query(Q);
    vector<ll> ans(N,INF);
    rep(i,N)cin >> pos[i] >> dir[i];
    rep(i,Q)cin >> query[i];
    rep(i,N-1){
        if(dir[i] == 1 && dir[i+1] == 2){
            ll mid = (pos[i] + pos[i+1])/2;
            if(abs(pos[i] - mid) < T){
                dfs(ans, mid, i);
                dfs(ans, mid, i+1);
                ans[i] = mid; ans[i+1] = mid;
            }
        }
    }
    rep(i,N){
        if(ans[i] == INF){
            ans[i] = pos[i] + T*d(dir[i]);
        }
    }
    rep(i,Q)cout << ans[query[i]-1] << endl;
    return 0;
}

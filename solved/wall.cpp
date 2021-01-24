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

int wall[208][208];
int rate[10][10];

int main(){
    int H,W;cin>>H>>W;
    rep(i,10)rep(j,10)cin>>rate[i][j];
    REP(i,H)REP(j,W)cin>>wall[i][j];

    vector<int> m(10);
    rep(i,10){
        
        if(i == 1)continue;
        int mi = inf;
        int par[9];
        int in = 0;
        rep(j,10){
            if(j !=i)par[in++] = j;
        }
        do{
            int tmp = 0;
            int now = i;
            rep(j,10){
                tmp += rate[now][par[j]];
                now = par[j];
                if(now == 1){
                    mi = min(mi,tmp);
                    break;
                }
            }
        }while(next_permutation(par,par+9));
        m[i] = mi;
    }
    
    int ans = 0;
    REP(i,H)REP(j,W){
        if(wall[i][j] == -1)continue;
        int from = wall[i][j];
        ans += m[from];
    }
    cout<<ans<<endl; return 0;
}

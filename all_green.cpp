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

int main(){
    int D,G;cin>>D>>G;
    vector<ip> p(D);
    int ans = inf;
    rep(i,D)cin>>p[i].first>>p[i].second;
    for(int bit = 0; bit<(1<<D); bit++){
        int res = G;
        int cnt = 0;
        bool used[D] = {false};
        for(int i = 0; i<D; ++i){
            if(bit & (1<<i)){
                res -= (p[i].second + p[i].first*(i+1)*100);
                cnt += p[i].first; used[i] = true;
            }
        }
        bool cnot = false;
        for(int i = D-1; i>=0&& res>0; --i){
            if(!used[i]){
                if(res>(p[i].first-1)*(i+1)*100)cnot = true;
                else cnt += ceil((double)res/((i+1)*100));
                break;
            }
        }
        if(cnot)continue;
        ans = min(ans, cnt);
    }
    cout<<ans<<endl; return 0;
}

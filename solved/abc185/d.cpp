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

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> bl(M+2);
    bl[0] = 0;
    REP(i,M)cin >> bl[i];
    bl[M+1] = N+1;
    sort(all(bl));
    vector<int> gap(M+1);
    rep(i,M+1)gap[i] = bl[i+1]-bl[i]-1;
    if(M == 0){
        cout << 1 << endl;
        return 0;
    }
    int k = inf;
    rep(i,M+1){
        if(gap[i] == 0)continue;
        k = min(k, gap[i]);
    }
    if(k == inf){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    rep(i,M+1){
        ans += (gap[i]/k) + (gap[i]%k != 0);
    }
    cout << ans << endl;
    return 0;
}

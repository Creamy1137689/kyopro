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
    int N, M, T;
    cin >> N >> M >> T;
    vector<P> c(M+2);
    c[0] = make_pair(0, 0);
    REP(i, M)cin >> c[i].first >> c[i].second;
    c[M+1] = make_pair(T, T);
    int nbt = N;
    bool ans = true;
    REP(i,M+1){
        nbt -= c[i].first - c[i-1].second;
        if(nbt <= 0)ans = false;
        nbt = min(N, nbt + (c[i].second - c[i].first));
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

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

int solve(P p){
    int x = p.first, y = p.second;
    int res = 0;
    res = max({abs(x)*2 -1, abs(y)*2 -1, abs(x) + abs(y)});
    cout << res << endl;
    return 0;
}

int main(){
    int T;
    cin >> T;
    vector<P> in(T);
    rep(i,T)cin >> in[i].first >> in[i].second;
    rep(i,T)solve(in[i]);
    return 0;
}

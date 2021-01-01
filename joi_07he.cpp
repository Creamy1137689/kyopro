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
#include <cassert>
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

struct s{
    ll rd, bd;
    int rs, bs;
};

vector<s> st(200);

ll solve(int rt){
    if(rt == -1)return 1;
    ll red = solve(st[rt].rs - 1);
    ll blue = solve(st[rt].bs - 1);

    ll nr = red * st[rt].rd;
    ll nb = blue * st[rt].bd;
    ll M = nr * nb / gcd(nr, nb);
    return M / st[rt].bd + M/st[rt].rd;
}

int main(){
    int N;
    cin >> N;
    rep(i,N)cin >> st[i].rd >> st[i].bd >> st[i].rs >> st[i].bs;
    //find root
    int root = inf;
    set<int> cnt;
    rep(i,N)cnt.insert(st[i].rs), cnt.insert(st[i].bs);
    REP(i,N)if(cnt.count(i) == 0)root = i-1;
    cout << solve(root) << endl;
    return 0;
}

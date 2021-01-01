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

int N;
vector<int> a(100100);

int solve(int pos, int to){
    int res = N;
    vector<int> k = a;
    vector<P> merged;
    k[pos] = to;
    int len = 0;
    rep(i,N){
        ++len;
        if(k[i] != k[i+1]){
            merged.push_back(make_pair(k[i], len));
            len = 0;
        }
    }
    int st = inf;
    rep(i, merged.size())if(merged[i].second >= 4)st = i;
    if(st == inf)return res;

    res -= merged[st].second;
    for(int l = st-1, r = st+1; l >= 0 && r < merged.size(); --l, ++r){
        int sum = merged[l].second + merged[r].second;
        if(merged[l].first == merged[r].first && sum >= 4){
            res -= sum;
            continue;
        }
        break;
    }
    return res;
}

int main(){
    cin >> N;
    a.resize(N);
    rep(i,N)cin >> a[i];
    a.push_back(inf);

    int ans = inf;
    rep(i,N){
        REP(j,3)ans = min(ans, solve(i,j));
    }
    cout << ans << endl;
    return 0;
}

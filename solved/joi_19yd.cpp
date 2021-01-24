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

template <typename T> vector<T> compress(vector<T> &X) {
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N+2, 0);
    vector<int> comp;
    map<int,vector<int>> where;
    REP(i,N)cin >> a[i];
    compress(a);
    rep(i,N+2)where[a[i]].push_back(i);
    for(auto x:where)comp.push_back(x.first);
    vector<bool> under(N+2, false);
    int linked = 0;
    int ans = 0;
    int pos = 0;
    rep(border,N+1){
        if(!(pos < comp.size()))break;
        while(comp[pos] <= border){
            for(auto x:where[comp[pos]]){
                int cnt = 0;
                under[x] = true;
                if(x > 0)if(under[x-1])++cnt;
                if(x < N + 1)if(under[x+1])++cnt;
                linked += 1-cnt;
            }
            ++pos;
            if(pos >= comp.size())break;
        }
        ans = max(ans, linked-1);
    }
    cout << ans << endl;
    return 0;
}

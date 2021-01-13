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
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n;
    cin >> n;
    dsu uf(400010);
    vector<P> input(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        uf.merge(a, b);
        input[i] = make_pair(a, b);
    }
    map<int, int> cnt;
    rep(i,n){
        int f = uf.merge(input[i].first, input[i].second);
        cnt[f] ++;
    }
    set<int> al;
    int ans = 0;
    rep(i,n){
        int f = uf.leader(input[i].first);
        if(al.count(f) == 0){
            ans += min(cnt[f], uf.size(f));
            al.insert(f);
        }
    }
    cout << ans << endl;
    return 0;
}

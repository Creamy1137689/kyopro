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
    vector<int> a(n), b(n), p(n);
    vector<int> who(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> p[i]; rep(i,n)p[i]--;
    rep(i,n)who[p[i]] = i;

    bool ok = true;
    rep(i,n){
        if(a[i] <= b[p[i]] && p[i] != i)ok = false;
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    vector<P> order(n);
    rep(i,n)order[i] = make_pair(a[i], i);
    sort(all(order));
    vector<P> ans;

    rep(i,n){
        int pos = order[i].second;
        if(p[pos] != pos){
            int sub = who[pos];
            ans.push_back(make_pair(pos+1, sub+1));
            swap(who[p[pos]], who[pos]);
            swap(p[pos], p[sub]);
        }
    }

    cout << ans.size() << endl;
    for(auto x:ans){
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}

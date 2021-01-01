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
    int N;
    cin >> N;
    vector<int> a(N+1);
    vector<int> b(N);
    vector<int> sa(N+1);
    vector<int> fmax(N+1, 0), lmax(N+1, 0);
    rep(i,N+1)cin >> a[i], sa[i] = a[i];
    rep(i,N)cin >> b[i];
    sort(all(sa));
    sort(all(b));
    rep(i,N){
        fmax[i+1] = max(fmax[i], max(sa[i]-b[i], 0));
    }
    for(int i = N-1; i >= 0; --i){
        lmax[i] = max(lmax[i+1], max(sa[i+1]-b[i], 0));
    }
    vector<int> ans(N+1);
    rep(k,N+1){
        int pos = lower_bound(all(sa), a[k]) - sa.begin();
        ans[k] = max(fmax[pos], lmax[pos]);
    }
    show(ans);
    return 0;
}

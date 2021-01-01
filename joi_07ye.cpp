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
    int A, B, C, N;
    int p,q,r;
    cin >> A >> B >> C >> N;
    vector<int> ans(A + B + C, 2);
    vector<int> a(N), b(N), c(N), res(N);
    rep(i,N){
        cin >> p >> q >> r >> res[i];
        --p; --q; --r;
        a[i] = p; b[i] = q; c[i] = r;
    }
    rep(i,N){
        if(res[i] == 1){
            ans[a[i]] = 1;
            ans[b[i]] = 1;
            ans[c[i]] = 1;
        }
    }
    rep(i,N){
        if(ans[a[i]] == 2 && ans[b[i]] == 1 && ans[c[i]] == 1)ans[a[i]] = 0;
        if(ans[a[i]] == 1 && ans[b[i]] == 2 && ans[c[i]] == 1)ans[b[i]] = 0;
        if(ans[a[i]] == 1 && ans[b[i]] == 1 && ans[c[i]] == 2)ans[c[i]] = 0;
    }
    rep(i, A + B + C)cout << ans[i] << endl;
    return 0;
}

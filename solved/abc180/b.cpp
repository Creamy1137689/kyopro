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
    vector<ll> a(N);
    rep(i,N)cin >> a[i];
    ll manh = 0;
    rep(i,N)manh += abs(a[i]);
    ll euc = 0;
    rep(i,N)euc += a[i] * a[i];
    ll che = 0;
    rep(i,N)che = max(che, abs(a[i]));
    cout << manh << endl;
    cout << fixed << setprecision(10) << sqrt(euc) << endl;
    cout << che << endl;
    return 0;
}

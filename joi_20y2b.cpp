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
    vector<LP> s(N);
    rep(i,N)cin >> s[i].first >> s[i].second;

    ll ans = 0;
    rep(i,N)ans = max(ans, s[i].first);
    sort(all(s), greater<LP>());
    s.push_back(make_pair(0LL, 0LL));
    rep(i,N){
        ans = max(ans, s[i].second);
        ans += s[i].first - s[i+1].first;
    }
    cout << ans << endl;
    return 0;
}

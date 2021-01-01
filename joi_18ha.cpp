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
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
    }
    ll ans = a[N-1]+1 - a[0];
    vector<ll> gap;
    rep(i,N-1){
        gap.push_back(a[i+1] - (a[i]+1));
    }
    sort(all(gap), greater<ll>());
    rep(i, min((ll)gap.size(), K-1)){
        ans -= gap[i];
    }
    cout << ans << endl;
    return 0;
}

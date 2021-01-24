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
    int N, M;
    cin >> N >> M;
    vector<ll> h(N);
    vector<ll> w(M);
    rep(i,N)cin >> h[i];
    rep(i,M)cin >> w[i];
    sort(all(h));
    vector<ll> dif_front(N/2);
    vector<ll> dif_back (N/2);
    rep(i,N/2){
        dif_front[i] = abs(h[2*i] - h[2*i + 1]);
    }
    sort(all(h), greater<ll>());
    rep(i,N/2){
        dif_back[i] = abs(h[2*i] - h[2*i + 1]);
    }
    sort(all(h));
    vector<ll> sum_df(N/2+1, 0);
    vector<ll> sum_db(N/2+1, 0);
    rep(i,N/2)sum_df[i+1] = sum_df[i] + dif_front[i];
    rep(i,N/2)sum_db[i+1] = sum_db[i] + dif_back[i];
    ll ans = INF;
    rep(i,M){
        auto it = lower_bound(all(h), w[i]);
        int pos = it - h.begin();
        ll tmp = 0;
        if(pos % 2 == 1){
            tmp += sum_df[pos/2];
            tmp += sum_db[(N-pos)/2];
            tmp += abs(w[i] - h[pos-1]);
        }else{
            tmp += sum_df[pos/2];
            tmp += sum_db[(N-pos)/2];
            tmp += abs(w[i] - h[pos]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

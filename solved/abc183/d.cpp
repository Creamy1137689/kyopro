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
    ll max_time = 200200;
    ll N, W, s, t, p;
    cin >> N >> W;
    vector<ll> need(max_time + 100, 0);
    rep(i,N){
        cin >> s >> t >> p;
        need[s] += p;
        need[t] -= p; 
    }
    REP(i,max_time)need[i] += need[i-1];
    cout << endl;
    bool ans = true;
    rep(i,max_time)if(need[i] > W)ans = false;
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

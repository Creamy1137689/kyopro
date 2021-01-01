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

ll solve(ll N, vector<ll> a){
    ll res = 0;
    sort(all(a));
    ll nin = a[0];
    ll nax = a[N-1];
    ll sum = 0;
    for(int i = 1; i < N-1; ++i){
        sum += nax - a[i];
    }
    ll L =0;
    rep(i,N)L += a[i];
    ll ideal = (L)/ (N-1) * (N-1)+ (N-1)*((L) % (N-1) != 0);
    res = max(ideal - L, sum - nin);
    return res;
}

int main(){
    int T;
    cin >> T;
    vector<ll> Ns(T);
    vector<vector<ll>> in(T);
    rep(i,T){
        cin >> Ns[i];
        in[i] = vector<ll> (Ns[i]);
        rep(j,Ns[i]){
            cin >> in[i][j];
        }
    }
    rep(i,T)cout << solve(Ns[i], in[i]) << endl;
    return 0;
}

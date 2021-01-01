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
    string s;
    cin >> N >> s;
    vector<ll> j(N+1, 0);
    vector<ll> o(N+1, 0);
    vector<ll> i(N+1, 0);
    vector<ll> jo(N+1, 0);
    vector<ll> oi(N+1, 0);
    rep(k,N){
        j[k+1] += j[k] + (s[k] == 'J');
        o[k+1] += o[k] + (s[k] == 'O');
        i[k+1] += i[k] + (s[k] == 'I');
    }

    rep(k,N){
        jo[k+1] += jo[k] + (s[k] == 'O') * j[k+1];
    }
    for(int k = N-1; k >= 0; --k){
        oi[k] += oi[k+1] + (s[k] == 'O') * (i[N] - i[k+1]);
    }
    ll al = 0;
    rep(k,N){
        if(s[k] == 'I')al += jo[k];
    }
    ll ans = 0;
    ans = max({ans, oi[0], jo[N]});
    rep(k,N-1){
        ans = max(ans, j[k] * (i[N] - i[k]));
    }
    cout << ans + al << endl;
    return 0;
}

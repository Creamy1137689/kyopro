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
    int N,M,t;
    cin >> N >> M;
    map<int, int> cnt;
    rep(i,N){
        cin >> t;
        cnt[t]++;
    }
    int nax = -1;
    int res = inf;
    for(auto x:cnt){
        if(nax < x.second){
            nax = x.second;
            res = x.first;
        }
    }
    if(nax > N/2)cout << res << endl;
    else cout << '?' << endl;
    return 0;
}

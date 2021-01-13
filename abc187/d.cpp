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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

bool com(lp a, lp b){
    return a.first*2 + a.second > b.first*2 + b.second;
}

int main(){
    int n;
    cin >> n;
    vector<lp> vot(n);
    rep(i,n)cin >> vot[i].first >> vot[i].second;
    sort(all(vot), com);
    ll aoki_sum = 0;
    rep(i,n)aoki_sum += vot[i].first;
    ll tak_sum = 0;
    int pos = 0;
    while(tak_sum <= aoki_sum){
        tak_sum += vot[pos].first + vot[pos].second;
        aoki_sum -= vot[pos].first;
        ++pos;
    }
    cout << pos << endl;
    return 0;
}

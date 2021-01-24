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

vector<vector<ll>> book(10, vector<ll>());
vector<vector<ll>> sums(10, vector<ll>());

ll memo[2020][12];
ll LAST = 9;

ll solve(ll rest, ll pos){
    if(memo[rest][pos] != -INF){
        return memo[rest][pos];
    }
    if(pos == LAST){
        if(rest < sums[LAST].size())return sums[LAST][rest] + rest*(rest-1);
        else return -INF;
    }
    ll res = -INF;
    rep(i,sums[pos].size()){
        if(rest-i < 0)break;
        ll tmp = sums[pos][i] + i*(i-1);
        tmp += solve(rest-i, pos+1);
        res = max(res, tmp);
    }
    return memo[rest][pos] = res;
}

int main(){
    int N, K, g, c;
    cin >> N >> K;
    rep(i,N){
        cin >> c >> g;
        --g;
        book[g].push_back(c);
    }
    rep(i,10)sort(all(book[i]), greater<ll>());
    rep(i,10){
        sums[i].resize(book[i].size() + 1);
        sums[i][0] = 0;
        rep(j,book[i].size()){
            sums[i][j+1] = sums[i][j] + book[i][j];
        }
    }
    rep(i,2020)rep(j,12)memo[i][j] = -INF;
    cout << solve(K, 0) << endl;
    return 0;
}

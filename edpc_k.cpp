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
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

//dp[i] = 0 ... not determined
//dp[i] = 1 ... win
//dp[i] = 2 ... lose
int N, K;
vector<int> a(100100);
vector<int> dp(100100, 0);

int solve(int k){
    if(dp[k] != 0)return dp[k];
    if(k < a[0])return dp[k] = 2;
    int res = 0;
    rep(i,N){
        if(k >= a[i])res = max(res, solve(k-a[i]));
    }
    return dp[k] = (res == 1 ? 2 : 1);
}

int main(){
    cin >> N >> K;
    rep(i,N)cin >> a[i];
    cout << (solve(K) == 1 ? "First" : "Second") << endl;
    return 0;
}

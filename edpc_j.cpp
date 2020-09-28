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

double dp[303][303][303]; 
int N;

double solve(int a, int b, int c){
    if(dp[a][b][c] != -1)return dp[a][b][c];
    double res = 0;
    double div = a + b + c;
    res += N/div;
    if(a > 0)res += solve(a-1, b, c)*a/div;
    if(b > 0)res += solve(a+1, b-1, c)*b/div;
    if(c > 0)res += solve(a, b+1, c-1)*c/div;
    return dp[a][b][c] = res;
}

int main(){
    rep(i,303)rep(j,303)rep(k,303)dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    int t, a[3] = {0};
    cin >> N;
    rep(i,N){
        cin >> t; --t; 
        ++a[t];
    }
    cout << fixed << setprecision(10)<< solve(a[0], a[1], a[2]) << endl;
    return 0;
}

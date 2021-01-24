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

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

//長さ
int lcs_len(string a, string b){
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    REP(i,a.size()){
        REP(j,b.size()){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                chmax(dp[i][j], dp[i-1][j]);
                chmax(dp[i][j], dp[i][j-1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}

//復元
string lcs(string a, string b){
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    vector<vector<P>> transition(a.size()+1, vector<P>(b.size()+1));
    REP(i,a.size()){
        REP(j,b.size()){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                transition[i][j] = make_pair(i-1, j-1);
            }else{
                if(chmax(dp[i][j], dp[i-1][j]))transition[i][j] = make_pair(i-1, j);
                if(chmax(dp[i][j], dp[i][j-1]))transition[i][j] = make_pair(i, j-1);
            }
        }
    }
    string res;
    int i = a.size(), j = b.size();
    while(true){
        if(i == 0 || j == 0)break;
        if(a[i-1] == b[j-1])res.push_back(a[i-1]);
        P from = transition[i][j];
        i = from.first;
        j = from.second;
    }
    reverse(all(res));
    return res;
}

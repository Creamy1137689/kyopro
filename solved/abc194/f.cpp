#include <atcoder/modint.hpp>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;
typedef modint1000000007 mint;

int main(){
    string s;
    int k;
    vector<int> v;
    cin >> s >> k;
    for(auto c:s){
        if('0' <= c && c <= '9') v.emplace_back((int)(c-'0'));
        else v.emplace_back((int)(10+c-'A'));
    }

    vector<vector<mint>> dp(s.size()+1, vector<mint>(18, 0));
    int state = 0;
    rep(i,s.size()){
        REP(j,16){
            dp[i+1][j] += dp[i][j] * j;
            dp[i+1][j+1] += dp[i][j] * (16-j);
        }
        dp[i+1][1] += dp[i][0]*15;
        dp[i+1][0] = dp[i][0];
        rep(j,v[i]){
            int nstate = state;
            if(i != 0 || j != 0)nstate |= (1 << j);
            dp[i+1][__builtin_popcount(nstate)] += 1;
        }
        state |= (1 << v[i]);
    }

    mint ans = dp[s.size()][k];
    if(__builtin_popcount(state) == k)ans++;
    cout << ans.val() << endl;
    return 0;
}

/* int main(){ */
/*     string s; */
/*     int k; */
/*     cin >> s >> k; */
/*     vector<char> v = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; */
/*     vector<vector<vector<ll>>> dp(s.size()+1, vector<vector<ll>>(17, vector<ll>(2, 0))); */
/*     dp[0][0][0] = 1; */
/*     set<char> al; */
/*     rep(i,s.size())rep(j,17)rep(m,2){ */
/*         int ni = i+1, nj = j+1, nm = m; */
/*         if(m == 0){ */
/*             for(auto nd:v){ */
/*                 if(nd == s[i]){ */
/*                     if(al.count(nd) == 0){ */
/*                         dp[ni][nj][0] += dp[i][j][m]; */
/*                         dp[ni][nj][0] %= MOD; */
/*                         al.insert(nd); */
/*                     }else{ */
/*                         dp[ni][j][0] += dp[i][j][m]; */
/*                         dp[ni][j][0] %= MOD; */
/*                     } */
/*                 }else if(nd < s[i]){ */
/*                     if(al.count(nd) == 0){ */
/*                         dp[ni][nj][1] += dp[i][j][m]; */
/*                         dp[ni][nj][1] %= MOD; */
/*                         al.insert(nd); */
/*                     }else{ */
/*                         dp[ni][j][1] += dp[i][j][m]; */
/*                         dp[ni][j][1] %= MOD; */
/*                     } */
/*                 } */
/*             } */
/*         }else{ */
/*             dp[ni][j][nm] += dp[i][j][m] * j; dp[ni][j][nm] %= MOD; */
/*             if(j < 16){dp[ni][nj][nm] += dp[i][j][m] * (16-j); dp[ni][nj][nm] %= MOD;} */
/*         } */
/*     } */
/*     cout << (dp[s.size()][k][0] + dp[s.size()][k][1]) % MOD << endl; */
/*     return 0; */
/* } */

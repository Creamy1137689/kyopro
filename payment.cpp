#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

int main(){
    string s; cin>>s;
    ll dp[s.size()]={0};
    dp[0] = min(s[0]-'0',1+10-(s[0]-'0'));
    for(int i = 1; i<s.size(); ++i){
        dp[i] = min(dp[i-1]+1+10-(s[i]-'0'), dp[i-1]+(s[i]-'0'));
    }
    cout<<dp[s.size()-1]<<endl;return 0;
}

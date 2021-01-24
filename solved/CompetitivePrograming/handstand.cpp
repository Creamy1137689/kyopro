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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int st = 1;
    if(s[0] == '0')st = 0;

//群数列化
    vector <int> sec; int p = 0;
    rep(i,n){
        sec.push_back(1);
        while(s[i] == s[i+1]){ ++i; ++sec[p]; }
        ++p;
    }

//累積和
    vector <int> sum(sec.size()+3,0);
    rep(i,sec.size()) sum[i+2] = sum[i+1] + sec[i]; 
    sum[sum.size()-1] = sum[sum.size()-2];

//処理
    int ans = -INF; k = k*2+1;
    for(int i = 0; i+k < sum.size(); ++i){
        if(i%2 == st){
            ans = max(ans, sum[i+k] - sum[i]);
        }
    }
    if(ans == -INF)ans = n;
    cout << ans << endl; return 0;
}

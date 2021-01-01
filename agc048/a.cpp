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

void solve(string s){
    //if(s.size() < 7){cout << -1 << endl; return ;}
    if(s[0] != 'a'){cout << 0 << endl;return;}
    string tar = "atcoder";
    if(s.size() > 7)if(s.substr(0,7) == tar){cout << 0 << endl; return;}
    rep(i,7){
        if(i < s.size()){
            if(s[i] > tar[i]){cout << 0 << endl; return;}
            if(s[i] == tar[i])continue;
            else break;
        }
    }
    rep(i,s.size()){
        if(s[i] != 'a'){
            if(s[i] > 't')cout << i - 1 << endl;
            else cout << i << endl;
            return ;
        }
    }
    cout << -1 << endl;
    //vector<char> can;
    //int ans = inf;
    //rep(i,s.size()){
    //    if(i < tar.size())can.push_back(tar[i]);
    //    int k = inf;
    //    rep(j,can.size()){
    //        if(s[i] > can[j])k = j;
    //    }
    //    if(k != inf){ans = min(ans, i-k);}
    //}
    //if(ans == inf)ans = -1;
    //cout << ans << endl;
    return ;
}

int main(){
    int T;
    cin >> T;
    vector<string> ss(T);
    rep(i,T)cin >> ss[i];
    rep(i,T)solve(ss[i]);
    return 0;
}

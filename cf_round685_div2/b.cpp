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

void solve(){
    int N, q, r, l;
    string s;
    cin >> N >> q >> s;
    rep(i,q){
        cin >> l >> r;
        string tar = s.substr(l-1, r-l+1);
        int now_tar = 0;
        vector<bool> chosen(N+10, false);
        for(int i = 0; i < N; ++i){
            if(tar[now_tar] == s[i] && !(chosen[i] && chosen[i+1])){
                ++now_tar;
                chosen[i+2] = true;
            }
            if(now_tar == tar.size())break;
        }
        if(now_tar == tar.size())cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    rep(i,t)solve();
    return 0;
}

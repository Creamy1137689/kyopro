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

int solve(){
    int n, zero, one, h;
    string s;
    cin >> n >> zero >> one >> h >> s;
    int cnt0 = 0, cnt1 = 0;
    rep(i,n)if(s[i] == '0')++cnt0; else ++cnt1;
    if(zero - one > 0 && abs(one - zero) > h){
        int ans = 0;
        ans += one*n;
        ans += cnt0*h;
        cout << ans << endl; return 0;
    }else if(one - zero > 0 && abs(one - zero) > h){
        int ans = 0;
        ans += zero*n;
        ans += cnt1*h;
        cout << ans << endl; return 0;
    }else{
        cout << zero*cnt0 + one*cnt1 << endl;
        return 0;
    }
}

int main(){
    int T;
    cin >> T;
    rep(_,T)solve();
    return 0;
}

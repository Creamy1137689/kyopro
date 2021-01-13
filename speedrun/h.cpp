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

string conv(ll a){
    string res;
    while(a > 0){
        if(a% 2 == 1)res.push_back('1');
        else res.push_back('0');
        a /= 2;
    }
    while(res.size() < 64){
        res.push_back('0');
    }
    reverse(all(res));
    return res;
}

string solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    string sa = conv(a), sb = conv(b), sc = conv(c);
    bool res = true;
    rep(i, sa.size()){
        if(sa[i] == '0' && sb[i] == '1')res = false;
        if(sa[i] == '0' && sc[i] == '1')res = false;
    }
    return (res ? "Yes" : "No");
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        cout << solve() << endl;
    }
    return 0;
}

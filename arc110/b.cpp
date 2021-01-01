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

int main(){
    int N;
    string s;
    cin >> N >> s;
    int tp1[3] = {1, 1, 0};
    int tp2[3] = {1, 0, 1};
    int tp3[3] = {0, 1, 1};
    ll ans = pow(10, 10);
    //tp1
    if(N == 1 && s == "1"){
        cout << ans*2 << endl;
        return 0;
    }
    bool ok = true;
    rep(i,N){
        if(s[i]-'0' != tp1[i%3])ok = false;
    }
    if(ok){
        ll len = N/3 + (N % 3 != 0);
        cout << ans - len + 1LL << endl;
        return 0;
    }
    //tp2
    ok = true;
    rep(i,N){
        if(s[i]-'0' != tp2[i%3])ok = false;
    }
    if(ok){
        ll len = (N+1)/3 + ((N+1) % 3 != 0);
        cout << ans - len + 1LL << endl;
        return 0;
    }
    //tp3
    ok = true;
    rep(i,N){
        if(s[i]-'0' != tp3[i%3])ok = false;
    }
    if(ok){
        ll len = (N+2)/3 + ((N+2) % 3 != 0);
        cout << ans - len + 1LL << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}

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

bool check(ll a, ll b, ll c, ll d){
    return a+b == c+d || a-b == c-d || abs(a-c) + abs(b-d) <= 3;
}

int ddx[4] = {3, 0, -3, 0};
int ddy[4] = {0, -3, 0, 3};

int main(){
    ll a, b,c,d;
    cin >>a >>b >> c >> d;
    int ans = 3;
    {
        if((a+b) % 2 == (c + d) % 2)ans = 2;
        for(int dy = -2; dy <= 2; ++dy){            
            for(int dx = -2; dx <= 2; ++dx){
                int na = dx+a, nb = dy+b;
                if(check(na, nb, c, d))ans = 2;
            }
        }
        rep(i,4){
            int na = ddx[i] + a, nb = ddy[i] + b;
            if(check(na, nb, c, d))ans = 2;
        }
        //
        for(int dy = -2; dy <= 2; ++dy){            
            for(int dx = -2; dx <= 2; ++dx){
                int nc = dx+c, nd = dy+d;
                if(check(a, b, nc, nd))ans = 2;
            }
        }
        rep(i,4){
            int nc = ddx[i] + c, nd = ddy[i] + d;
            if(check(a, b, nc, nd))ans = 2;
        }
    }
    if(check(a, b, c, d))ans = 1;
    if(a == c && b == d)ans = 0;
    cout << ans << endl;
    return 0;
}

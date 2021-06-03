#include <bits/stdc++.h>
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

int main(){
    int ans = -1;
    int len = -1;
    REP(i,1000000){
        ll n = i;
        int cnt = 0;
        while(n != 1){
            if(n % 2 == 1){
                n = 3*n + 1;
            }else{
                n /= 2;
            }
            ++cnt;
        }
        if(chmax(len, cnt))ans = i;
    }
    cout << ans << endl;
    return 0;
}

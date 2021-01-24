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

string solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int t = (a + b + c);
    if(t % 3 != 0)return "no";
    t /= 3;
    int lay = min({a, b, c});
    if(t % 3 == 0 && t/3 <= lay)return "yes";
    else return "no";
}

int main(){
    int t;
    cin >> t;
    while(t -- > 0){
        cout << solve() << endl;
    }
    return 0;
}

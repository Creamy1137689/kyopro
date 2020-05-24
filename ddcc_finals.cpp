#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int x,y; cin>>x>>y;
    int ans = 0;
    if(x == 1)ans += 300000;
    if(x == 2)ans += 200000;
    if(x == 3)ans += 100000;
    if(y == 1)ans += 300000;
    if(y == 2)ans += 200000;
    if(y == 3)ans += 100000;

    if(ans == 600000)ans += 400000;
    cout<<ans<<endl;

}

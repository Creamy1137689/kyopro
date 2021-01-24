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
#define REP(i,n) for(int i = 1; i<n; ++i)
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n; cin>>n;
    vector<pair<string,int>> pl(n); rep(i,n){ cin>>pl[i].first>>pl[i].second; }
    string x; cin>>x;

    int ans = 0; bool on = false;
    rep(i,n){
        if(on)ans += pl[i].second;
        if(pl[i].first == x)on = true;
    }
    cout<<ans<<endl; return 0;
}

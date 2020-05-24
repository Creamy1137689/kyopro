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
    int N,H; cin>>N>>H;
    vector<ip> k(N);
    rep(i,N)cin>>k[i].second>>k[i].first;
    int hi = 0;
    rep(i,N)hi = max(hi, k[i].second);
    sort(k.begin(),k.end());
    int ans = 0;
    for(int i = N-1;i>=0; --i){
        if(k[i].first>hi){H-=k[i].first; ans++;}
        if(H<=0){cout<<ans<<endl; return 0;}
    }
    ans += ceil(H/(double)hi);
    cout<<ans<<endl; return 0;
}

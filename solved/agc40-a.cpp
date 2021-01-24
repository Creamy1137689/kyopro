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
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<' ';
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    string s; cin>>s;
    vll cl(s.size()+1,0);
    vll cr(s.size()+1,0);

    cl[0] = 0;
    rep(i,s.size()){
        if(s[i] == '<')cl[i+1] = cl[i]+1;
    }
    cr[s.size()] = 0;
    for(int i = s.size()-1; i>=0; --i){
        if(s[i] == '>')cr[i] = cr[i+1]+1;
    }
    ll ans = 0;
    rep(i,s.size()+1){
        ans += max(cl[i],cr[i]);
    }
    cout<<ans<<endl; return 0;
}
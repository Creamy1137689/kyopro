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
    vint c(s.size(),0);
    if(s[0]=='A'||s[0]=='T'||s[0]=='G'||s[0]=='C')c[0] = 1;
    int ans = c[0];
    for(int i = 1; i<s.size(); ++i){
        if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C')c[i] = c[i-1]+1;
        ans = max(ans, c[i]);
    }
    cout<<ans<<endl; return 0;
}

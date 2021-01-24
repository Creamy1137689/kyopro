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
    string s; cin>>s;
    int t; cin>>t;
    int x = 0, y = 0;
    int ind = 0;
    rep(i,s.size()){
        if(s[i] == 'L')--x;
        if(s[i] == 'R')++x;
        if(s[i] == 'D')--y;
        if(s[i] == 'U')++y;
        if(s[i] == '?')++ind;
    }
    x = abs(x); y = abs(y);
    if(t == 1){
        cout<<x+y+ind<<endl; return 0;
    }else{
        if(x+y-ind>=0)cout<<x+y-ind<<endl;
        else cout<<((abs(x+y-ind)%2==1)?1:0)<<endl;
        return 0;
    }
}

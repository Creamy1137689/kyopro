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
    int n;string s;
    cin>>n>>s;
    int ans = 0;
    for(int bar = 1; bar<n; ++bar){
        map<char,bool> p;
        rep(i,bar){
            p[s[i]] = false;
        }
        int tmp = 0;
        for(int i = bar; i<n; ++i){
            if(p.count(s[i]))if(p[s[i]] == false){
                tmp ++;p[s[i]] = true;
            }
        }
        ans = max(ans,tmp);
    }
    cout<<ans<<endl; return 0;
}

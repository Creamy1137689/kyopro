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
const int inf = 537427207;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n,m;cin>>n>>m;
    string a[n];
    rep(i,n)cin>>a[i];
    string tmp[m];
    rep(i,m)cin>>tmp[i];
    rep(i,n-m+1){
        rep(j,n-m+1){
            bool ans = true;
            rep(p, m){
                rep(q,m){
                    if(a[i+p][j+q] != tmp[p][q])ans = false;
                }
            }
            if(ans){cout<<"Yes"<<endl; return 0; }
        }
    }
    cout<<"No"<<endl; return 0;
}
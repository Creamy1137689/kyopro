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
    int n; cin>>n;
    int sum = 0;
    vint t(n); rep(i,n){cin>>t[i]; sum += t[i];}
    int m; cin>>m;
    vector<ip> d(m); rep(i,m){cin>>d[i].first>>d[i].second; d[i].first--;}
    rep(i,m){
        cout<<sum-t[d[i].first]+d[i].second<<endl; 
    }   
}
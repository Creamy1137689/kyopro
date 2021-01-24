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
    int n;cin>>n;
    vector<pair<int,string>> t(n);
    ll sum = 0;
    rep(i,n){
        int p; string s; cin>>s>>p;
        sum += p;
        t[i].first = p; 
        t[i].second = s;
    }
    sort(t.begin(),t.end());
    if(sum/2<t[n-1].first){cout<<t[n-1].second<<endl; return 0;}
    else cout<<"atcoder"<<endl; return 0;
}

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
    int n,m; cin>>n>>m;
    vint p(n+1); REP(i,n)cin>>p[i];
 
    vint com((n+1)*(n+1));
    int count = 0;
    rep(i,(n+1))rep(j,(n+1)){
        if(m >= p[i]+p[j]){
            com[count++] = p[i]+p[j];
        }
    }
    sort(com.begin(),com.begin()+count);

    showall(com);
 
    int ans = 0;
    rep(i,count){
        if(com[i]>m)break;
        int left = lower_bound(com.begin(), com.end(), m+1-com[i]) - com.begin();
        ans = max(ans, com[i]+com[left-1]);
    }
    
    cout<<ans<<endl; return 0;
}

/*
int main(){
    int MAX_N = 1001;
    int n,m; cin>>n>>m;
    int p[MAX_N] = {0};
    REP(i,n+1)cin>>p[i];

    ll com[MAX_N*MAX_N] = {0};
    int count = 0;
    rep(i,n)rep(j,n+1){
        com[count++] = p[i] + p[j];
    }

    sort(com, com+count);
    ll ans = 0;
    rep(i,count){
        if (pp[i] > m) break;
        int left = lower_bound(com,com+count, m+1-com[i])-com;
        ans = max(ans,com[i]+com[left-1]);
    }
    cout<<ans<<endl; return 0;
}
*/
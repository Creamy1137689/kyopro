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
    vector<bool> al(1000000000,false);
    int n,k;cin>>n>>k;
    vector<string> per(n);
    rep(i,n)cin>>per[i];
    sort(per.begin(),per.end());
    int ans = 0;
    do{
        string s;
        rep(i,k){
            s += per[i];
        }
        int m = atoi(s.c_str());
        if(!al[m]){ans++; al[m] = true;}
    }while(next_permutation(per.begin(),per.end()));
    cout<<ans<<endl; return 0;
}

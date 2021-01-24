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
    int n; cin>>n;
    int p[5] = {3,5,7,11,13};
    int ans = 0;
    for(int i = 0; i<5; ++i){
        for(int j = i+1; j<5; ++j){
            for(int k = j+1; k<5; ++k)if(p[i]*p[j]*p[k]<=n)ans++;
        }
    }
    if(n>=135)ans++; if(n>=189)ans++;
    cout<<ans<<endl; return 0;
}

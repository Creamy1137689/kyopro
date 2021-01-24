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

int digit_sum(int n){
    int ans = 0;
    while(n!=0){ans+=n%10; n /= 10;}
    return ans;
}

int main(){
    int n,a,b; cin>>n>>a>>b;
    int ans = 0;
    REP(i,n){
        int tp = digit_sum(i);
        if(a<=tp && tp<=b)ans+=i;
    }
    cout<<ans<<endl;
}

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
    int a,b,c; cin>>a>>b>>c;
    int x; cin>>x;
    int ans = 0;
    for(int acnt = 0; acnt<=a&& acnt*500<=x; ++acnt){
        int sum = acnt*500;
        for(int bcnt = 0; bcnt<=b&& sum+bcnt*100<=x; ++bcnt){
            if(0<=(x-sum-bcnt*100)/50&&(x-sum-bcnt*100)/50<=c)ans++;
        }
    }
    cout<<ans<<endl; return 0;
}

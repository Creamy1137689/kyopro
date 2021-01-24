#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n,a,b;cin>>n>>a>>b;
    int ans = 0;
    rep(i,n){
        string s; int d; 
        cin>>s>>d;
        if(d<a)d = a;
        if(b<d)d = b;
        ans += ((s=="West")?-1:1)*d;
    }
    if(ans == 0){cout<<0<<endl; return 0;}
    cout<<((ans<0)?"West":"East")<<' '<<abs(ans)<<endl; return 0;
}

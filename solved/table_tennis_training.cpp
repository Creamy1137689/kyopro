#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    ll n,a,b; cin>>n>>a>>b;
    ll gap = b-a-1;
    if(gap%2==1){
        cout<<(gap+1LL)/2LL<<endl;
    }else{
        cout<<min(a-1LL,n-b)+1+gap/2<<endl;
    }
}

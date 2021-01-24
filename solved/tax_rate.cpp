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
#define showall(obj) for(auto x:obj)cout<<x<<endl
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
    n *= 100;
    if(n%108 == 0){cout<<n/100/1.08<<endl; return 0;}
    
    n /=100;
    int ex = n/1.08;
    for(int d = -1; d<=3; ++d){
        int tmp = (ex+d)*1.08;
        if(tmp == n){cout<<ex+d<<endl; return 0;}
    }
    cout<<":("<<endl; return 0;
}

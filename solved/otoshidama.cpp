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
    int N,Y;cin>>N>>Y;
    int x,y,z;
    for(x = 0; x*10000<=Y; x++){
        for(y = 0; x*10000+y*5000<=Y; ++y){
            if((Y-x*10000-y*5000)/1000 == N-x-y){printf("%d %d %d\n",x,y,N-x-y); return 0;}
        }
    }
    cout<<"-1 -1 -1"<<endl; return 0;
}

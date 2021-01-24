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
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    vint x(N+1), y(M+1); 
    x[0] = X; y[0] = Y;
    rep(i,N)cin>>x[i+1];
    rep(i,M)cin>>y[i+1];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x[N] < y[0])cout<<"No War"<<endl;
    else cout<<"War"<<endl; return 0;
}

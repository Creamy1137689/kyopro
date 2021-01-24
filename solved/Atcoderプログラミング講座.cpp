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

int wall[208][208];
int rate[10][10];

int main(){
    double N; int K;
    cin>>N>>K;
    vector<double> r(N);
    rep(i,N)cin>>r[i];
    sort(r.begin(),r.end());
    double rate = 0;
    for(int i = N-K; i<(int)N ;++i){
        rate = (rate+r[i])/2;
    }
    cout<<fixed<<setprecision(10)<<rate<<endl; return 0;
}

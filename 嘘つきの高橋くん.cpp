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
    int n;cin>>n;
    set<int> t;
    rep(i,2){int p; cin>>p; t.insert(p);}
    int k; cin>>k;
    rep(i,k){
        int p; cin>>p;
        if(t.count(p)==1){cout<<"NO"<<endl; return 0;}
        else t.insert(p);
    }
    cout<<"YES"<<endl; return 0;
}

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
    string s,t; cin>>s;
    t = "b";
    if(s == "b"){cout<<0<<endl; return 0;}
    REP(i,n){
        if(i%3==1){t.insert(0,"a");t.push_back('c');}
        if(i%3==2){t.insert(0,"c");t.push_back('a');}
        if(i%3==0){t.insert(0,"b");t.push_back('b');}
        if(s==t){cout<<i<<endl; return 0;}
    }
    cout<<-1<<endl; return 0;
}

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
    string s, t;cin>>s>>t;
    rep(i,s.size()){
        if(s[i]==t[i])continue;
        char cs = s[i], ct = t[i];
        if(cs == '@' && (ct == 'a' || ct == 't'|| ct == 'c'|| ct == 'o'|| ct == 'd'|| ct == 'e'|| ct == 'r'))continue;
        if(ct == '@' && (cs == 'a' || cs == 't'|| cs == 'c'|| cs == 'o'|| cs == 'd'|| cs == 'e'|| cs == 'r'))continue;
        cout<<"You will lose"<<endl; return 0;
    }
    cout<<"You can win"<<endl; return 0;
}

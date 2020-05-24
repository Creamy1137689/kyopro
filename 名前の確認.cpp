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
    string s;cin>>s;
    if('A'<= s[0]&&s[0]<='Z');
    else s[0] = (char)(s[0]-'a'+'A');
    REP(i,s.size()-1){
        if('a'<= s[i]&&s[i]<='z');
        else s[i] = (char)(s[i]-'A'+'a');
    }
    cout<<s<<endl; return 0;
}

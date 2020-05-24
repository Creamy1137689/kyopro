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
    bool ans = true;
    if(s[0] != 'A')ans = false;
    int e = 0;
    for(int i = 1; i<s.size(); ++i){
        if(2<=i && i<=s.size()-2 && s[i] == 'C')e++;
        else if(isupper(s[i]))ans = false;
    }
    if(e != 1)ans = false;
    cout<<((ans)?"AC":"WA")<<endl; return 0;
}

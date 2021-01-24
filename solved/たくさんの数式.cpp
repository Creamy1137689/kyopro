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

ll sum(string s){
    ll ans = 0; ll tmp = 0;
    rep(i,s.size()){
        if(tmp == 0)tmp += s[i]-'0';
        else if(s[i] == '+'){ans += tmp; tmp = 0;}
        else {tmp *= 10; tmp += s[i]-'0';}
    }
    ans += tmp; return ans;
}

int main(){
    string s; cin>>s;
    ll ans = 0;
    for(int bit = 0; bit < (1<<s.size()-1); ++bit){
        string t = s; int ad = 1;
        for(int i = 0; i<s.size()-1; ++i){
            if(bit & (1<<i)){t.insert(i+ad,"+"); ++ad;}
        }
        ans += sum(t);
    }
    cout<<ans<<endl; return 0;
}

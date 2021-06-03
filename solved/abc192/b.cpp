#include <bits/stdc++.h>
#include <atcoder/all>
#include <cctype>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    string s;
    cin >> s;
    bool ans = true;
    rep(i,s.size()){
        if(i % 2){
            if(!('A' <= s[i] && s[i] <= 'Z'))ans = false;
        }else{
            if(!('a' <= s[i] && s[i] <= 'z'))ans = false;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

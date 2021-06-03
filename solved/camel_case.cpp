#include <bits/stdc++.h>
using namespace std;

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
    string ans = "", t = "";
    cin >> s;
    int l = 0, r = s.size();
    while(s[l] == '_' && l < r){
        ans.push_back('_');
        ++l;
    }
    while(s[r-1] == '_' && l < r){
        t.push_back('_');
        --r;
    }
    bool cam = false, und = false;
    if(('A' <= s[l] && s[l] <= 'Z') || ('0' <= s[l] && s[l] <= '9')){
        cout << s << endl;
        return 0;
    }
    for(; l < r; ++l){
        if(s[l] == '_' && l + 1 < r){
            und = true;
            if('a' <= s[l+1] && s[l+1] <= 'z'){
                ans.push_back('A' + s[l+1] - 'a');
                ++l;
            }else{
                cout << s << endl;
                return 0;
            }
        }else if('A' <= s[l] && s[l] <= 'Z'){
            cam = true;
            ans.push_back('_');
            ans.push_back('a' + s[l] - 'A');
        }else{
            ans.push_back(s[l]);
        }
    }
    ans += t;
    if(cam ^ und)cout << ans << endl;
    else cout << s << endl;
    return 0;
}

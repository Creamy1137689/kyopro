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
#include<atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    ll N;
    string s, t;
    cin >> N >> s >> t;
    ll ans = 0;
    ll spos = 0;
    for(ll i = 0; i < N; ++i){
        spos = max(spos, i+1);
        if(t[i] == '0'){
            if(s[i] == '1'){
                while(spos < N){
                    if(s[spos] == '0')++spos;
                    else break;
                }
                if(spos == N){cout << -1 << endl; return 0;}
                ans += 1 + (spos - i - 1);
                s[spos] = '0';
            }else{
                //nothing
            }
        }

        if(t[i] == '1'){
            if(s[i] == '1'){
                //nothing
            }else{
                while(spos < N){
                    if(s[spos] == '0')++spos;
                    else break;
                }
                if(spos == N){cout << -1 << endl; return 0;}
                ans += spos - i;
                s[spos] = '0';
            }
        }
    }
    cout << ans << endl;
    return 0;
}

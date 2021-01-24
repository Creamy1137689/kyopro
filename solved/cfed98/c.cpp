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
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int solve(string s){
    int res = 0;
    int N = s.size();
    int maru = 0;
    int kaku = 0;
    rep(i,N){
        if(s[i] == '(')++maru;
        if(s[i] == ')'){
            if(maru > 0){
                ++res;
                --maru;
            }
        }
    }
    rep(i,N){
        if(s[i] == '[')++kaku;
        if(s[i] == ']'){
            if(kaku > 0){
                ++res;
                --kaku;
            }
        }
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    vector<string> ss(T);
    rep(i,T)cin >> ss[i];
    rep(i,T)cout << solve(ss[i]) << endl;
    return 0;
}

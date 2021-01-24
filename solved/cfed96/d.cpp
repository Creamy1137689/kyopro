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

void solve(int N, string s){
    int res = 0;
    queue<P> q;
    s += 'a';
    int cnt = 0;
    int rest = 0;
    rep(i,N){
        ++cnt;
        if(s[i] != s[i+1]){
            q.emplace(s[i]-'0', cnt);
            rest += cnt - 1;
            cnt = 0;
        }
    }
    int seisanyou = 0;
    while(!q.empty()){
        P p = q.front();
        q.pop();
        int bf = p.second;
        p.second = max(1, p.second-seisanyou);
        seisanyou -= bf-p.second;
        if(p.second == 1){
            if(rest > 0){
                --rest;
                ++seisanyou;
            }else{
                if(!q.empty())q.pop();
            }
        }else{
            rest -= p.second-1;
        }
        ++res;
    }
    cout << res << endl;
}

//void solve(int N, string s){
//    int res = 0;
//    queue<P> q;
//    s += 'a';
//    int cnt = 0;
//    rep(i,N){
//        ++cnt;
//        if(s[i] != s[i+1]){
//            q.emplace(s[i]-'0', cnt);
//            cnt = 0;
//        }
//    }
//    while(!q.empty()){
//        P p = q.front();
//        q.pop();
//        if(p.second == 1){
//            if(!q.empty()){
//                q.pop();
//            }
//        }
//        ++res;
//    }
//    cout << res << endl;
//}

int main(){
    int t;
    cin >> t;
    vector<int> ns(t);
    vector<string> ss(t);
    rep(i,t)cin >> ns[i] >> ss[i];
    rep(i,t)solve(ns[i], ss[i]);
    return 0;
}

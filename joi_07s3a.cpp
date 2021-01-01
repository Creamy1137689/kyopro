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

ll fact(int N){
    ll res = 1;
    REP(i,N)res *= i;
    return res;
}

ll perm(map<char,int> arg){
    int cnt = 0;
    for(auto x:arg)cnt += x.second;
    ll res = fact(cnt);
    for(auto x:arg)res /= fact(x.second);
    return res;
}

ll solve(string tar, map<char, int> ex){
    //for(auto x:ex)printf("%c x %d\n", x.first, x.second);
    if(tar == "")return 0;
    ll res = 0;
    for(auto x:ex){
        if(x.first == tar[0])break;
        map<char, int> arg = ex;
        arg[x.first]--;
        if(arg[tar[0]] == 0)arg.erase(tar[0]);
        res += perm(arg);
    }
    //cout << res << endl;
    ex[tar[0]]--;
    if(ex[tar[0]] == 0)ex.erase(tar[0]);
    res += solve(tar.substr(1, tar.size()-1), ex);
    return res;
}

int main(){
    string s;
    cin >> s;
    map<char, int> ex;
    rep(i,s.size())ex[s[i]]++;
    cout << solve(s, ex) + 1<< endl;
}

//ll perm(string s){
//    map<char,int> cnt;
//    rep(i,s.size())cnt[s[i]]++;
//    ll res = fact(s.size());
//    for(auto x:cnt)res /= fact(x.second);
//    return res;
//}
//
//ll solve(string now, string tar){
//    if(now == "")return 0;
//    ll res = 0;
//    sort(all(now));
//    ll index = -1;
//    set<char> cnt;
//    rep(i,now.size()){
//        cnt.insert(now[i]);
//        if(tar[0] == now[i]){
//            index = i;
//            break;
//        }
//    } 
//    now.erase(now.begin()+index);
//    res += perm(now) * (cnt.size()-1);
//    printf("[now = %s, tar = %s] res = %lld\n", now.c_str(), tar.c_str(), res);
//    res += solve(now, tar.substr(1, tar.size()-1));
//    return res;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    string now = s;
//    sort(all(now));
//    cout << solve(now, s) + 1<< endl;
//    return 0;
//}
//
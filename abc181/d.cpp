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

map<int,int> need(int k){
    int zero = 3;
    map<int,int> res;
    while(k > 0){
        --zero;
        res[k%10]++;
        k /= 10;
    }
    res[0] += zero;
    return res;
}

int dig(int k){
    int res = 0;
    while(k > 0)res ++, k /= 10;
    return res;
}

int main(){
    string s;
    cin >> s;
    map<int, int> cnt;
    rep(i,s.size()){
        cnt[s[i]-'0']++;
    }
    int lim = inf;
    if(s.size() <= 3){
        cnt[0] += 3-s.size();
    }
    bool ans = false;
    rep(i,1000){
        int k = i;
        if(dig(i) > s.size())break;
        if(i % 8 == 0){
            map<int,int> nd = need(i);
            bool ok = true;
            for(auto x:nd){
                if(cnt[x.first] < x.second)ok = false;
            }
            ans = ans || ok;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

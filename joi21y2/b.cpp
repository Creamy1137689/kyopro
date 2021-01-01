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

map<string, int> memo;

string rv(string s, int p){
    string t;
    for(int i = p; i >= 0; --i){
        t += s[i];
    }
    for(int i = p+1; i < s.size(); ++i){
        t += s[i];
    }
    return t;
}

void solve(string str, string tar){
    queue<string> q;
    memo[str] = 0;
    q.push(str);
    while(!q.empty()){
        string s = q.front();
        q.pop();
        rep(i,s.size()){
            string n = rv(s, i);
            if(memo.count(n) == 0){
                memo[n] = memo[s]+1;
                q.push(n);
            }
        }
    }
    return ;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<string> ss(Q);
    rep(i,Q){
        cin >> ss[i];
    }
    rep(i,Q){
        string ideal = ss[i];
        sort(all(ideal));
        solve(ideal, ss[i]);
        cout << memo[ss[i]] << endl;;
    }
    return 0;
}

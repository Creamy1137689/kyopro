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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<string> ss(n);
    rep(i,n)cin >> ss[i];
    map<string, P> ch;
    rep(i,n){
        string s = ss[i];
        if(s[0] == '!'){
            string t = s.substr(1, s.size()-1);
            ch[t].first = inf;
        }else{
            ch[s].second = inf;
        }
    }
    for(auto x:ch){
        if(x.second.first == inf && x.second.second == inf){
            cout << x.first << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}

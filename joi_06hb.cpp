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

int main(){
    int N, K, t;
    cin >> N >> K;
    vector<int> a;
    bool con = false;
    rep(i,K){
        cin >> t;
        if(t == 0)con = true;
        else a.push_back(t);
    }
    sort(all(a));
    a.push_back(inf);
    vector<P> segment;
    int l = 0, r = 0;
    rep(i,a.size()-1){
        ++r;
        if(a[r-1] + 1 != a[r]){
            segment.push_back(make_pair(l,r));
            l = r;
        }
    }
    int liner = 0, db = 0;
    if(con){
        rep(i,segment.size()-1){
            P x = segment[i], nt = segment[i+1];
            if(x.second == nt.first)db = max(db, x.second-x.first + nt.second - nt.first);
        }
    }
    for(auto x:segment)liner = max(liner, x.second - x.first);
    cout << max(liner, db) + (con) << endl;
    return 0;
}

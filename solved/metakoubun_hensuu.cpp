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
    int a, b, t;
    cin >> a >> b;
    set<int> all;
    set<int> A,both;
    rep(i,a){
        cin >> t;
        all.insert(t);
        A.insert(t);
    }
    rep(i,b){
        cin >> t;
        all.insert(t);
        if(A.count(t) == 1)both.insert(t);
    }
    cout << fixed << setprecision(10) << (double)both.size() / (double)all.size() << endl;
    return 0;
}

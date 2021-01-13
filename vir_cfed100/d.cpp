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

int solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n)cin >> v[i];
    vector<int> al(2*n);
    vector<int> no;
    rep(i,2*n)al[i] = i+1;
    set_difference(all(al), all(v), inserter(no, no.end()));
    int er = 2*n;
    while(v[v.size() -1] == er){
        v.pop_back();
        --er;
    }
    int ans = 1;
    for(int i = v.size()-1; i >= 0; --i){
        if(v[i] != i+1){
            if(no.back() > v[i]){
                ++ans;
                no.pop_back();
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        cout << solve() << endl;
    }
    return 0;
}

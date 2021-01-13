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
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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


P solve(int l, int r, vector<int>& a){
    if(l + 2 == r){
        if(a[l] < a[l+1])return make_pair(l+1, l);
        else return make_pair(l, l+1);
    }
    int mid = (l+r)/2;
    P left = solve(l, mid, a);
    P right = solve(mid, r, a);
    /* printf("[left : %d - %d]\n", left.first, left.second); */
    /* printf("[right : %d - %d]\n", right.first, right.second); */
    if(a[left.first] > a[right.first])return make_pair(left.first, right.first);
    else return make_pair(right.first, left.first);
}

int main(){
    int n;
    cin >> n;
    int nn = pow(2, n);
    vector<int> a(nn);
    rep(i,nn){
        cin >> a[i];
    }
    cout << solve(0, nn, a).second + 1 << endl;
    return 0;
}

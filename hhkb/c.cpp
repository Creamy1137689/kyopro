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
    int N;
    cin >> N;
    vector<int> p(N);
    vector<bool> used(300000, false);
    vector<int> ans(N);
    rep(i,N)cin >> p[i];
    int now_ans = 0;
    rep(i,N){
        int t = p[i];
        used[t] = true;
        while(used[now_ans])++now_ans;
        ans[i] = now_ans;
    }
    rep(i,N)cout << ans[i] << endl;
    return 0;
}

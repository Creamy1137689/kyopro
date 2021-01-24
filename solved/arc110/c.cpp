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

void op(int t, vector<int> &p, vector<pair<bool, bool>> &gap, queue<int> &q){
    int d = p[t] - (t+1);
    if(d > 0){
        gap[t].first = true;
        if(gap[t].first && gap[t].second)q.push(t);
    }
    if(d < 0){
        gap[t-1].second = true;
        if(gap[t-1].first && gap[t-1].second)q.push(t-1);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N)cin >> p[i];
    queue<int> q;
    vector<pair<bool, bool>> gap(N-1, make_pair(false, false));
    rep(i,N){
        op(i, p, gap, q);
    }
    vector<int> ans;
    vector<bool> used(N-1, false);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(used[t])continue;
        used[t] = true;
        gap[t].first = false; gap[t].second = false;
        ans.push_back(t+1);
        swap(p[t], p[t+1]);
        op(t, p, gap, q);
        op(t+1, p, gap, q);
    }
    bool ok = true;
    rep(i,N)if(p[i] != i+1)ok = false;
    if(!ok || ans.size() != N-1)cout << -1 << endl;
    else{
        rep(i,N-1)cout << ans[i] << endl;
    }
    return 0;
}

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

int N;
vector<string> edge(100);

void dfs(int s, vector<int> &count, vector<bool> &al){
    al[s] = true;
    ++count[s];
    rep(i,N){
        if(edge[s][i] == '1' && !al[i]){
            dfs(i, count, al);
        }
    }
    return ;
}

int main(){
    cin >> N;
    rep(i,N)cin >> edge[i];

    vector<int> count(N, 0);
    rep(i,N){
        vector<bool> al(N, false);
        dfs(i, count, al);
    }

    double ans = 0;
    rep(i,N){
        ans += 1.00 / count[i];
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}

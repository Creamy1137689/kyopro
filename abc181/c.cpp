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

int main(){
    int N;
    cin >> N;
    vector<P> d(N);
    rep(i,N)cin >> d[i].first >> d[i].second;
    bool ok = false;
    rep(i,N){
        rep(j,N){
            rep(k,N){
                if(i == j || j == k || k == i)continue;
                int dx1 = d[i].first - d[j].first;
                int dx2 = d[i].first - d[k].first;
                int dy1 = d[i].second - d[j].second;
                int dy2 = d[i].second - d[k].second;
                if(dx2 * dy1 == dx1 * dy2){
                    ok = true;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

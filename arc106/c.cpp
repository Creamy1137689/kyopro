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
    ll N, M;
    cin >> N >> M;
    if(M == 0){
        REP(i,N){
            cout << i*2 << ' ' << i * 2 + 1 << endl;
        }
        return 0;
    }
    if(M < 0 || M > N-2){cout << -1 << endl; return 0;}
    vector<P> ans;
    ans.push_back(make_pair(1, 10000000));
    REP(i,M+1){
        ans.push_back(make_pair(i*2, i*2 + 1));
    }
    REP(i,N-M-2){
        ans.push_back(make_pair(i*2 + 10000000, i*2 + 1 + 10000000));
    }
    for(auto x:ans)cout << x.first << ' ' << x.second << endl;
    return 0;
}

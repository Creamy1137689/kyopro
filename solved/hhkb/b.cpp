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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> nap(H + 2, vector<char>(W+2, '#'));
    REP(i,H)REP(j,W)cin >> nap[i][j];
    int ans = 0;
    REP(i,H)REP(j,W){
        if(nap[i][j] == '.' && nap[i+1][j] == '.')++ans;
        if(nap[i][j] == '.' && nap[i][j+1] == '.')++ans;
    }
    cout << ans << endl;
    return 0;
}
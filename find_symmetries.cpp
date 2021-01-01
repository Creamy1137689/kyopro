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

int N;
vector<vector<char>> nap(2*305, vector<char>(2*305));

bool is_ok(int h, int w){
    bool res = true;
    rep(i,N)rep(j,N){
        if(nap[h+i][w+j] != nap[h+j][w+i])res = false;
    }
    return res;
}

int main(){
    char c;
    cin >> N;
    rep(i,N)rep(j,N){
        cin >> c;
        nap[i][j] = nap[i+N][j] = nap[i][j+N] = nap[i+N][j+N] = c;
    }
    int ans = 0;
    rep(i,N){
        if(is_ok(i,0))ans += N-i;
        if(i != 0)if(is_ok(0,i))ans += N-i;
    }
    cout << ans << endl;
    //rep(i,2*N){rep(j,2*N)cout << nap[i][j]; cout << endl;}
    return 0;
}

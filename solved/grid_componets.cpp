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
    int a, b;
    cin >> a >> b;
    int w = 100, h = 100;
    char ans[100][100];
    rep(i,50)rep(j,100)ans[j][i] = '#';
    rep(i,50)rep(j,100)ans[j][i+50] = '.';
    --a; --b;
    rep(k,a){
        int i = (k % 50) * 2;
        int j = k / 50 * 2;
        ans[i][j] = '.';
    }
    rep(k,b){
        int i = (k % 50) * 2;
        int j = k / 50 * 2;
        ans[i][99-j] = '#';
    }
    cout << w << ' ' << h << endl;
    rep(i,h){rep(j,w)cout << ans[i][j]; cout << endl;}
    return 0;
}

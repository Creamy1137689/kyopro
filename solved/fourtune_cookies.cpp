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
    vector<int> ck(4);
    rep(i,4)cin >> ck[i];
    bool ok = false;
    rep(i,2){
        rep(j,2){
            rep(k,2){
                rep(m,2){
                    int a = 0, b = 0;
                    if(i == 0)a += ck[0]; else b += ck[0];
                    if(j == 0)a += ck[1]; else b += ck[1];
                    if(k == 0)a += ck[2]; else b += ck[2];
                    if(m == 0)a += ck[3]; else b += ck[3];
                    if(a == b)ok = true;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

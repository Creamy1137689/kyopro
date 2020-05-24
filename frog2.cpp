#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<n; ++i)
typedef long long ll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;


//aとbのうち小さい値をaとして採用する
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}

int main(){
    int n,k;cin>>n>>k;
    vector<ll> h(110000);rep(i,n)cin>>h[i];
    vector<ll> costs(110000,INF);

    costs[0] = 0;
    rep(i,n){
        for(int j = 1; j<=k; ++j){
            chmin(costs[i+j], costs[i]+abs(h[i+j]-h[i]));
        }
    }
    cout<<costs[n-1]<<endl;return 0;
}

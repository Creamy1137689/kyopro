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
    int N, M;
    cin >> N >> M;
    vector<LP> drink(N);
    rep(i,N)cin >> drink[i].first >> drink[i].second;
    sort(all(drink));
    ll money = 0, bottle = 0;
    for(int i = 0; i < N && bottle < M; ++i){
        if(drink[i].second >= M-bottle){
            money += drink[i].first * (M-bottle);
            bottle = M;
        }else{
            money += drink[i].second * drink[i].first;
            bottle += drink[i].second;
        }
    }
    cout << money << endl;
    return 0;
}

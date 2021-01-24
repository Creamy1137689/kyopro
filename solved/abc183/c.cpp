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
    int N, K;
    cin >> N >> K;
    int cost[8][8];
    rep(i,N)rep(j,N)cin >> cost[i][j];
    int rot[N-1];
    rep(i,N-1)rot[i] = i+1;
    int ans = 0;
    do{
        int sum = 0;
        vector<int> route(N+1,0);
        rep(i,N-1)route[i+1] = rot[i];
        for(int i = 1; i <= N; ++i){
            sum += cost[route[i-1]][route[i]];
        }
        if(sum == K)++ans;
    }while(next_permutation(rot, rot + N-1));
    cout << ans << endl;
    return 0;
}

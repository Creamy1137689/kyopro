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
const int MOD = (int)1e5;

int main(){
    int N, M;
    vector<int> town(100100);
    vector<int> sche(100100);
    cin >> N >> M;
    rep(i,N-1)cin >> town[i];
    rep(i,M)cin >> sche[i];
    vector<int> sum(100100);
    rep(i,N-1)sum[i+1] = sum[i] + town[i];
    int now = 0;
    int ans = 0;
    rep(i,M){
        int l = now;
        int r = now + sche[i];
        if(l > r)swap(l,r);
        ans += sum[r] - sum[l];
        ans %= MOD;
        now += sche[i];
    }
    cout << ans << endl;
    return 0;
}

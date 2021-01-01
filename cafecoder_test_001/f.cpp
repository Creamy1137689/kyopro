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

int cdist(int a, int b){
    if(a > b)swap(a,b);
    int res1, res2;
    res1 = b - a;
    res2 = a + N - b;
    return min(res1, res2);
}

int main(){
    cin >> N;
    vector<int> a(N);
    vector<int> pos(N);
    rep(i,N){
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    int ans = N;
    int nxt_num = 0;
    int now_pos = 0;
    bool bf = false;
    while(nxt_num < N-1){
        int d = cdist(now_pos, pos[nxt_num]);
        if(bf)d = min(d, cdist(pos[nxt_num-2], pos[nxt_num]));
        int exceed_d = cdist(now_pos, pos[nxt_num + 1]);
        bf = false;
        //printf("[now = %d] -> [d = %d, exdd = %d, now_pos = %d, ans = %d]\n", nxt_num + 1, d, exceed_d, now_pos, ans);
        if(exceed_d <= d && (abs(pos[nxt_num] - pos[nxt_num+1]) == 1)){
            now_pos = pos[nxt_num+1];
            nxt_num += 2;
            ans += exceed_d;
            bf = true;
        }else{
            now_pos = pos[nxt_num];
            ++nxt_num;
            ans += d;
        }
    }
    cout << ans << endl;
    if(nxt_num == N-1){
        int d = cdist(now_pos, pos[nxt_num]);
        if(bf)d = min(d, cdist(pos[nxt_num-2], pos[nxt_num]));
        ans += d;
    }  
    cout << ans << endl;
    return 0;
}

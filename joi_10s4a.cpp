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

struct da{
    int op_time = inf;
    int ac_time = inf;
    int wa_cnt = 0;
};

int main(){
    int N, M, T, X, Y;
    cin >> N >> M >> T >> X >> Y;
    vector<vector<da>> part(N, vector<da>(M));
    vector<int> score(M);
    rep(i,M)cin >> score[i];
    string com;
    int t, n, m;
    rep(i,Y){
        cin >> t >> n >> m >> com;
        --n; --m;
        if(com == "open"){
            if(part[n][m].op_time == inf)part[n][m].op_time = t;
        }else if(com == "correct"){
            if(part[n][m].ac_time == inf)part[n][m].ac_time = t;
        }else{
            ++part[n][m].wa_cnt;
        }
    }
    vector<int> ans(N);
    rep(i,N){
        int el = 0;
        rep(j,M){
            if(part[i][j].ac_time != inf){
                el += max(X, score[j] - (part[i][j].ac_time - part[i][j].op_time) - 120*part[i][j].wa_cnt);
            }
        }
        ans[i] = el;
    }
    rep(i,N)cout << ans[i] << endl;
    return 0;
}

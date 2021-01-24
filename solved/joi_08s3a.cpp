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

struct st{int p, q, r, s;};

int main(){
    int N, a, b;
    cin >> N >> a >> b;
    vector<st> paper(N);
    rep(i,N)cin >> paper[i].p >> paper[i].q >> paper[i].r >> paper[i].s;
    vector<int> ans(6000, 0);
    rep(i,N){
        st me = paper[i];
        int w = me.r - me.p + 1, h = me.s - me.q + 1;
        vector<vector<int>> cnt(w + 1, vector<int>(h + 1, 0)); 
        rep(j,N){
            if(i == j)continue;
            st you = paper[j];
            if(me.p > you.r || me.r < you.p)continue;
            if(me.q > you.s || me.s < you.q)continue;
            //if(i == 0)printf("%d, is ok!!\n", j);
            int a,b,c,d;
            a = max(me.p, you.p);
            b = max(me.q, you.q);
            c = min(me.r, you.r);
            d = min(me.s, you.s);
            a -= me.p; c -= me.p;
            b -= me.q; d -= me.q;
            ++c; ++d;
            cnt[a][b]++; cnt[c][b]--; cnt[a][d]--; cnt[c][d]++;
            //if(i == 0){
            //    printf("[a,b],(c,d) = [%d, %d], (%d, %d)\n", a, b, c,d);
            //    rep(k, w){
            //        rep(m, h)cout << cnt[k][m] << ' ';
            //        cout << endl;
            //    }
            //}
        }
        rep(k, w+1)REP(m, h){
            cnt[k][m] += cnt[k][m-1];
        }
        rep(m, h+1)REP(k,w){
            cnt[k][m] += cnt[k-1][m];
        }
        rep(k, w)rep(m, h){
            ans[cnt[k][m]+1]++;
        }
        //for debug
        //if(i == 0)rep(k, w){
        //    rep(m, h)cout << cnt[k][m] << ' ';
        //    cout << endl;
        //}
        //end debug
    }
    //REP(i,a*b)cout << ans[i] << ' '; cout << endl;
    for(int i = 5500; i >= 0; --i){
        if(ans[i] != 0){
            cout << i << endl;
            cout << ans[i]/i << endl;
            return 0;
        }
    }
    return 0;
}

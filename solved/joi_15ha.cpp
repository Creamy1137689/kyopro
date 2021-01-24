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

struct tr{ ll a, b, c; };

int main(){
    int N, M;
    cin >> N >> M;
    vector<tr> trans(N);
    vector<int> sche(M);
    vector<int> visit_cnt(N, 0);
    rep(i,M)cin >> sche[i];
    rep(i,N-1)scanf("%lld %lld %lld", &trans[i].a, &trans[i].b, &trans[i].c);
    rep(i,M-1){
        int l = sche[i];
        int r = sche[i+1];
        --l; --r;
        if(l > r){
            swap(l,r);
        }
        ++visit_cnt[l];
        --visit_cnt[r];
    }
    REP(i,N-1){
        visit_cnt[i] += visit_cnt[i-1];
    }
    ll ans = 0;
    rep(i,N-1){
        //cout << trans[i].c / (trans[i].a - trans[i].b) + (trans[i].c % (trans[i].a - trans[i].b)!=0) << endl;
        if((trans[i].c / (trans[i].a - trans[i].b) + (trans[i].c % (trans[i].a - trans[i].b) != 0)) > visit_cnt[i])ans += trans[i].a * visit_cnt[i];
        else {
            ans += trans[i].c;
            ans += trans[i].b * visit_cnt[i];
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

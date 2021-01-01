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
    ll N, K, M;
    cin >> K >> N >> M;
    ll border = K / 12 + (K % 12 != 0);
    vector<ll> score(K);
    vector<ll> maxs(K);
    vector<ll> mins(K);
    vector<ll> ans_detwin;
    vector<ll> ans_probwin;
    rep(i,K){
        cin >> score[i];
        mins[i] = score[i];
        maxs[i] = score[i] + (N-M)*100;
    }
    int add = (N-M > 0);
    sort(all(mins));
    sort(all(maxs));
    rep(i,K){
        auto it = upper_bound(all(maxs), score[i]);
        ll pos = maxs.end() - it;
        //printf("[%d]->[%d] with %d query is -> %lld\n",i, pos, (int)(it - maxs.begin()),  score[i]);
        if(pos < border + add)ans_detwin.push_back(i+1);
    }
    rep(i,K){
        auto it = upper_bound(all(mins), score[i] + (N-M)*100);
        ll pos = mins.end() - it;
        if(pos < border)ans_probwin.push_back(i+1);
    }
    rep(i,ans_detwin.size())cout << ans_detwin[i] << endl;
    cout << "--------" << endl;
    rep(i,ans_probwin.size())cout << ans_probwin[i] << endl;
    return 0;
}

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
#define show(obj) for(auto x:obj)cout<<x<<' ';cout<<endl;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> lp;
typedef pair<double, double> FP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll sign(ll a, ll b){return (a <= b ? 1 : -1);}

int solve(){
    int n;
    cin >> n;
    vector<P> v(n+1);
    rep(i, n)cin >> v[i].first >> v[i].second;
    int ans = 0;
    ll goaltime = 0, goalpos = 0, sttime = 0, stpos = 0;
    vector<lp> timeline;
    rep(i, n){
        if(v[i].first >= goaltime){
            timeline.push_back(make_pair(v[i].first, goalpos));
            stpos = goalpos;
            sttime = v[i].first;
            goalpos = v[i].second;
            goaltime = sttime + abs(stpos - goalpos);
        }else{
            int pos = stpos + (v[i].first - sttime) * sign(stpos, goalpos);
            timeline.push_back(make_pair(v[i].first, pos));
        }
    }
    timeline.push_back(make_pair(inf, goalpos));
    /* rep(i,timeline.size())printf("[time:%lld]->[%lld]\n", timeline[i].first, timeline[i].second); */
    rep(i,n){
        int x = v[i].second;
        int bpos = timeline[i].second;
        int apos = timeline[i+1].second;
        if((bpos <= x && x <= apos) || (bpos >= x && x >= apos))++ans;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        cout << solve() << endl;
    }
    return 0;
}

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
    int N, Q, k;
    string s;
    cin >> N >> s >> Q;
    vector<ll> sumc(N+1, 0);
    vector<ll> sumd(N+1, 0);
    vector<int> posc;
    vector<int> posd;
    rep(i,N){
        sumc[i+1] = sumc[i] + (s[i] == 'C');
        sumd[i+1] = sumd[i] + (s[i] == 'D');
        if(s[i] == 'C')posc.push_back(i);
        if(s[i] == 'D')posd.push_back(i);
    }
    rep(_,Q){
        cin >> k;
        ll ans = 0;
        rep(i,N){
            if(s[i] == 'M'){
                int lbc = lower_bound(all(posc), i)-posc.begin();
                int ubd = lower_bound(all(posd), i)-posd.begin();
                if(ubd == 0 || lbc == posc.size())continue;
                --ubd;
                lbc = posc[lbc]; ubd = posd[ubd];
                int lbd = max(0, i-k), ubc = min(i + k, N-1);
                //printf("D...[%d, %d) -> M...[%d, %d)\n", lbd, ubd, lbc, ubc);
                ans += (sumc[ubc+1] - sumc[lbc]) * (sumd[ubd+1] - sumd[lbd]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

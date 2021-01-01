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
    int N;
    string s;
    cin >> N >> s;
    vector<int> ac(N+1, 0);
    vector<int> tc(N+1, 0);
    vector<int> gc(N+1, 0);
    vector<int> cc(N+1, 0);
    rep(i,N){
        ac[i+1] = ac[i] + (s[i] == 'A');
        tc[i+1] = tc[i] + (s[i] == 'T');
        gc[i+1] = gc[i] + (s[i] == 'G');
        cc[i+1] = cc[i] + (s[i] == 'C');
    }
    int ans = 0;
    for(int l = 0; l < N; ++l){
        for(int r = l + 1; r <= N; ++r){
            if((ac[r] - ac[l]) == (tc[r] - tc[l]) && (gc[r] - gc[l]) == (cc[r] - cc[l]))++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

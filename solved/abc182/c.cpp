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
    string s;
    cin >> s;
    int ans = inf;
    for(int bit = 1; bit < (1 << s.size()); ++bit){
        int sum = 0;
        int cnt = 0;
        rep(i,s.size()){
            if(bit & (1 << i)){
                ++cnt;
                sum += s[i] - '0';
            }
        }
        if(sum % 3 == 0)ans = min(ans, (int)s.size() - cnt);
    }
    if(ans == inf)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

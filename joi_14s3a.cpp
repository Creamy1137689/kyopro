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
    map<P, vector<int>> locate;
    int ji = 0, jo = 0;
    locate[make_pair(ji, jo)].push_back(0);
    rep(i,N){
        if(s[i] == 'J')++ji, ++jo;
        if(s[i] == 'I')--ji;
        if(s[i] == 'O')--jo;
        locate[make_pair(ji,jo)].push_back(i+1);
    }
    int ans = 0;
    for(auto x:locate)ans = max(ans, *(x.second.rbegin()) - *(x.second.begin()));
    cout << ans << endl;
    return 0;
}
